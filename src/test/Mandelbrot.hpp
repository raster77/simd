#ifndef MANDELBROT_HPP_
#define MANDELBROT_HPP_

#include <simd/sse.hpp>
#include <simd/avx.hpp>
#include <cmath>
#include <vector>

struct Config {
    std::size_t width = 3840;
    std::size_t height = 2160;
    std::size_t depth = 512;
    std::pair<float, float> xLimit = { -2.5, 1.5 };
    std::pair<float, float> yLimit = { -1.5, 1.5 };
    std::size_t iterations = 1024;
};

namespace Mandelbrot {

  Config conf;

  void mandelScalar(std::vector<unsigned char>& image) {
    float xdiff = conf.xLimit.second - conf.xLimit.first;
    float ydiff = conf.yLimit.second - conf.yLimit.first;
    float iterScale = 1.f / conf.iterations;
    float depthScale = conf.depth - 1;

    for (std::size_t y = 0; y < conf.height; y++) {
      for (std::size_t x = 0; x < conf.width; x++) {
        float cr = x * xdiff / conf.width + conf.xLimit.first;
        float ci = y * ydiff / conf.height + conf.yLimit.first;
        float zr = cr;
        float zi = ci;
        std::size_t k = 0;
        float mk = 0.f;
        while (++k < conf.iterations) {
          float zr1 = zr * zr - zi * zi + cr;
          float zi1 = zr * zi + zr * zi + ci;
          zr = zr1;
          zi = zi1;
          mk += 1.f;
          if (zr * zr + zi * zi >= 4.0f) {
            break;
          }
        }
        mk *= iterScale;
        mk = std::sqrt(mk);
        mk *= depthScale;
        int pixel = static_cast<int>(mk);

        for (std::size_t i = 0; i < 3; i++) {
          image[y * conf.width * 3 + x * 3 + i] = pixel;
        }

      }
    }
  }

  void mandelSSE2(std::vector<unsigned char>& image) {
    simd::float4 xMin(conf.xLimit.first);
    simd::float4 yMin(conf.yLimit.first);
    simd::float4 xScale((conf.xLimit.second - conf.xLimit.first) / conf.width);
    simd::float4 yScale((conf.yLimit.second - conf.yLimit.first) / conf.height);
    simd::float4 threshold(4);
    simd::float4 one(1);
    simd::float4 iterScale(1.f / conf.iterations);
    simd::float4 depthScale(conf.depth - 1);

    for (std::size_t y = 0; y < conf.height; y++) {
      for (std::size_t x = 0; x < conf.width; x += 4) {
        simd::float4 mx(x, x + 1, x + 2, x + 3);
        simd::float4 my(y);
        simd::float4 cr = mx * xScale + xMin;
        simd::float4 ci = my * yScale + yMin;
        simd::float4 zr = cr;
        simd::float4 zi = ci;
        std::size_t k = 1;
        simd::float4 mk(k);
        while (++k < conf.iterations) {
          /* Compute z1 from z0 */
          simd::float4 zr2 = zr * zr;
          simd::float4 zi2 = zi * zi;
          simd::float4 zrzi = zr * zi;

          zr = (zr2 - zi2) + cr;
          zi = (zrzi + zrzi) + ci;

          /* Increment k */
          zr2 = zr * zr;
          zi2 = zi * zi;
          simd::float4 mag2 = zr2 + zi2;
          simd::float4 mask = mag2.lesser(threshold);
          mk += mask & one;

          /* Early bailout? */
          if (_mm_movemask_ps(mask.get()) == 0) {
            break;
          }
        }
        mk *= iterScale;
        mk = simd::sse::sqrt(mk);
        mk *= depthScale;

        unsigned char *dst = &image[0] + y * conf.width * 3 + x * 3;
        for (std::size_t i = 0; i < 4; i++) {
          dst[i * 3 + 0] = mk[i];
          dst[i * 3 + 1] = mk[i];
          dst[i * 3 + 2] = mk[i];
        }

      }
    }
  }

  void mandelAVX(std::vector<unsigned char>& image) {
    simd::float8 xMin(conf.xLimit.first);
    simd::float8 yMin(conf.yLimit.first);
    simd::float8 xScale((conf.xLimit.second - conf.xLimit.first) / conf.width);
    simd::float8 yScale((conf.yLimit.second - conf.yLimit.first) / conf.height);
    simd::float8 threshold(4);
    simd::float8 one(1);
    simd::float8 iterScale(1.f / conf.iterations);
    simd::float8 depthScale(conf.depth - 1);

    for (std::size_t y = 0; y < conf.height; y++) {
      for (std::size_t x = 0; x < conf.width; x += 8) {
        simd::float8 mx(x, x + 1, x + 2, x + 3, x + 4, x + 5, x + 6, x + 7);
        simd::float8 my(y);
        simd::float8 cr = mx * xScale + xMin;
        simd::float8 ci = my * yScale + yMin;
        simd::float8 zr = cr;
        simd::float8 zi = ci;
        std::size_t k = 1;
        simd::float8 mk(k);
        while (++k < conf.iterations) {
          /* Compute z1 from z0 */
          simd::float8 zr2 = zr * zr;
          simd::float8 zi2 = zi * zi;
          simd::float8 zrzi = zr * zi;

          zr = (zr2 - zi2) + cr;
          zi = zrzi + zrzi + ci;

          /* Increment k */
          zr2 = zr * zr;
          zi2 = zi * zi;
          simd::float8 mag2 = zr2 + zi2;

          simd::float8 mask = mag2.lesser(threshold);
          mk += mask & one;
          /* Early bailout? */
          if (_mm256_testz_ps(mask.get(), _mm256_set1_ps(-1))) {
            break;
          }
        }
        mk *= iterScale;
        mk = simd::avx::sqrt(mk);
        mk *= depthScale;

        unsigned char *dst = &image[0] + y * conf.width * 3 + x * 3;
        for (std::size_t i = 0; i < 8; i++) {
          dst[i * 3 + 0] = mk[i];
          dst[i * 3 + 1] = mk[i];
          dst[i * 3 + 2] = mk[i];

          dst[i * 3 + 4] = mk[i];
          dst[i * 3 + 5] = mk[i];
          dst[i * 3 + 6] = mk[i];
        }
      }
    }
  }

}
#endif /* MANDELBROT_HPP_ */
