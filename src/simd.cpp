
#include "Chrono.hpp"
#include "test/Mandelbrot.hpp"
#include "test/TestSIMD.hpp"
#include <cstdio>
#include <iostream>
#include <vector>
#include <array>


int main() {

  testFloat4(utl::BinaryTest::ShowTest::ERRORS);
  std::cout << std::endl;
  testFloat8(utl::BinaryTest::ShowTest::ERRORS);
  std::cout << std::endl;
  testDouble2(utl::BinaryTest::ShowTest::ERRORS);
  std::cout << std::endl;
  testDouble4(utl::BinaryTest::ShowTest::ERRORS);

  Mandelbrot::conf.width = 1920;
  Mandelbrot::conf.height = 1080;
  std::vector<unsigned char> datas;
  const std::size_t SZ = Mandelbrot::conf.width * Mandelbrot::conf.height * 3;
  datas.resize(SZ);

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Mandelbrot test" << std::endl;
  std::cout << "  Size       : " << Mandelbrot::conf.width << "x" << Mandelbrot::conf.height << std::endl;
  std::cout << "  Iterations : " << Mandelbrot::conf.iterations << std::endl;
  std::cout << "  Depth      : " << Mandelbrot::conf.depth << std::endl << std::endl;

  utl::Chrono c;

  c.start();
  Mandelbrot::mandelScalar(datas);
  std::cout << "  No SIMD : " << c.asMilliSeconds() << " ms" << std::endl;

  datas.clear();
  datas.resize(SZ);

  c.start();
  Mandelbrot::mandelSSE2(datas);
  std::cout << "  SSE     : " << c.asMilliSeconds() << " ms" << std::endl;

  datas.clear();
  datas.resize(SZ);

  c.start();
  Mandelbrot::mandelAVX(datas);
  std::cout << "  AVX     : " << c.asMilliSeconds() << " ms" << std::endl;

  return 0;
}
