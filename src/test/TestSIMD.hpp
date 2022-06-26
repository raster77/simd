#ifndef TESTSIMD_HPP_
#define TESTSIMD_HPP_

#include <simd/avx.hpp>
#include <simd/sse.hpp>
#include "BinaryTest.hpp"

void testFloat4(const utl::BinaryTest::ShowTest & show = utl::BinaryTest::ShowTest::ERRORS) {

  utl::BinaryTest test("Test simd::float4");

  test.add("float4()", true, std::function<bool()>([]() {
    simd::float4 f;
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 0) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("float4(1.f)", true, std::function<bool()>([]() {
    simd::float4 f(1.f);
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 1.f) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("float4(1.f, 2.f, 3.f, 4.f)", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4(__m128&)", true, std::function<bool()>([]() {
    simd::float4 ref(1.f, 2.f, 3.f, 4.f);
    simd::float4 f(ref.get());
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4++", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    f++;
    return f[0] == 2.f && f[1] == 3.f && f[2] == 4.f && f[3] == 5.f;
  }));

  test.add("float4--", true, std::function<bool()>([]() {
    simd::float4 f(2.f, 3.f, 4.f, 5.f);
    f--;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4 = __m128&", true, std::function<bool()>([]() {
    simd::float4 ref(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = ref.get();
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4 = float4&", true, std::function<bool()>([]() {
    simd::float4 ref(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = ref;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4.set(1.f, 2.f, 3.f, 4.f)", true, std::function<bool()>([]() {
    simd::float4 f;
    f.set(1.f, 2.f, 3.f, 4.f);
    return f[0] == 4.f && f[1] == 3.f && f[2] == 2.f && f[3] == 1.f;
  }));

  test.add("float4.setReversed(1.f, 2.f, 3.f, 4.f)", true, std::function<bool()>([]() {
    simd::float4 f;
    f.setReversed(1.f, 2.f, 3.f, 4.f);
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4 + float4", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 + f2;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f;
  }));

  test.add("float4 + __mm128&", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 + f2.get();
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f;
  }));

  test.add("float4 + 1.f", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 + 1;
    return f[0] == 2.f && f[1] == 3.f && f[2] == 4.f && f[3] == 5.f;
  }));

  test.add("float4 += float4", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f += f1;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f;
  }));

  test.add("float4 += _m128&", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f += f1.get();
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f;
  }));

  test.add("float4 += 1.f", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    f += 1.f;
    return f[0] == 2.f && f[1] == 3.f && f[2] == 4.f && f[3] == 5.f;
  }));

  test.add("float4 - float4", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 - f2;
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f;
  }));

  test.add("float4 - __mm128&", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 - f2.get();
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f;
  }));

  test.add("float4 - 1.f", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 - 1.f;
    return f[0] == 0.f && f[1] == 1.f && f[2] == 2.f && f[3] == 3.f;
  }));

  test.add("float4 -= float4", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f -= f1;
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f;
  }));

  test.add("float4 -= __mm128&", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f -= f1.get();
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f;
  }));

  test.add("float4 -= 1.f", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    f -= 1.f;
    return f[0] == 0.f && f[1] == 1.f && f[2] == 2.f && f[3] == 3.f;
  }));

  test.add("float4 * float4", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 * f2;
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f;
  }));

  test.add("float4 * __mm128&", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 * f2.get();
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f;
  }));

  test.add("float4 * 2.f", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 * 2.f;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f;
  }));

  test.add("float4 *= float4", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f *= f1;
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f;
  }));

  test.add("float4 *= __mm128&", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f *= f1.get();
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f;
  }));

  test.add("float4 *= 1.f", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    f *= 2.f;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f;
  }));

  test.add("float4 / float4", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 / f2;
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f;
  }));

  test.add("float4 / __mm128&", true, std::function<bool()>([]() {
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    simd::float4 f2(1.f, 2.f, 3.f, 4.f);
    simd::float4 f = f1 / f2.get();
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f;
  }));

  test.add("float4 / 2.f", true, std::function<bool()>([]() {
    simd::float4 f1(2.f, 4.f, 6.f, 8.f);
    simd::float4 f = f1 / 2.f;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4 /= float4", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f /= f1;
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f;
  }));

  test.add("float4 /= __mm128&", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 3.f, 4.f);
    simd::float4 f1(1.f, 2.f, 3.f, 4.f);
    f /= f1.get();
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f;
  }));

  test.add("float4 /= 2.f", true, std::function<bool()>([]() {
    simd::float4 f(2.f, 4.f, 6.f, 8.f);
    f /= 2.f;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f;
  }));

  test.add("float4 == float4", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(2.f);
    return f == f2;
  }));

  test.add("float4.equal(float4)", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(2.f);
    simd::float4 res = f.equal(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 != float4", true, std::function<bool()>([]() {
    simd::float4 f(1.f, 2.f, 2.f, 2.f);
    simd::float4 f2(2.f);
    return f != f2;
  }));

  test.add("float4.notEqual(float4)", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(1.f);
    simd::float4 res = f.notEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 > float4", true, std::function<bool()>([]() {
    simd::float4 f(4.f);
    simd::float4 f2(2.f);
    return f > f2;
  }));

  test.add("float4.greater(float4)", true, std::function<bool()>([]() {
    simd::float4 f(4.f);
    simd::float4 f2(2.f);
    simd::float4 res = f.greater(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 >= float4", true, std::function<bool()>([]() {
    simd::float4 f(4.f);
    simd::float4 f2(4.f);
    return f >= f2;
  }));

  test.add("float4.greaterEqual(float4)", true, std::function<bool()>([]() {
    simd::float4 f(4.f);
    simd::float4 f2(4.f);
    simd::float4 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 >= float4", true, std::function<bool()>([]() {
    simd::float4 f(14.f);
    simd::float4 f2(4.f);
    return f >= f2;
  }));

  test.add("float4.greaterEqual(float4)", true, std::function<bool()>([]() {
    simd::float4 f(14.f);
    simd::float4 f2(4.f);
    simd::float4 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4.lesser(float4)", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(4.f);
    simd::float4 res = f.lesser(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 < float4", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(4.f);
    return f < f2;
  }));

  test.add("float4.lesserEqual(float4)", true, std::function<bool()>([]() {
    simd::float4 f(4.f);
    simd::float4 f2(4.f);
    simd::float4 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 <= float4", true, std::function<bool()>([]() {
    simd::float4 f(4.f);
    simd::float4 f2(4.f);
    return f <= f2;
  }));

  test.add("float4 <= float4", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(4.f);
    return f <= f2;
  }));


  test.add("float4.lesserEqual(float4)", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    simd::float4 f2(4.f);
    simd::float4 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float4 size() == 4", true, std::function<bool()>([]() {
    simd::float4 f(2.f);
    return f.size() == 4;
  }));

  test.run(show);
}

void testFloat8(const utl::BinaryTest::ShowTest & show = utl::BinaryTest::ShowTest::ERRORS) {

  utl::BinaryTest test("Test simd::float8");

  test.add("float8()", true, std::function<bool()>([]() {
    simd::float8 f;
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 0) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("float8(1.f)", true, std::function<bool()>([]() {
    simd::float8 f(1.f);
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 1.f) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("float8(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f)", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8(__m256&)", true, std::function<bool()>([]() {
    simd::float8 ref(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f(ref.get());
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8++", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f++;
    return f[0] == 2.f && f[1] == 3.f && f[2] == 4.f && f[3] == 5.f
                && f[4] == 6.f && f[5] == 7.f && f[6] == 8.f && f[7] == 9.f;
  }));

  test.add("float8--", true, std::function<bool()>([]() {
    simd::float8 f(2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f);
    f--;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8 = __m256&", true, std::function<bool()>([]() {
    simd::float8 ref(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = ref.get();
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8 = float8&", true, std::function<bool()>([]() {
    simd::float8 ref(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = ref;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8.set(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f)", true, std::function<bool()>([]() {
    simd::float8 f;
    f.set(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    return f[7] == 1.f && f[6] == 2.f && f[5] == 3.f && f[4] == 4.f
           && f[3] == 5.f && f[2] == 6.f && f[1] == 7.f && f[0] == 8.f;
  }));

  test.add("float8.setReversed(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f)", true, std::function<bool()>([]() {
    simd::float8 f;
    f.setReversed(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8 + float8", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 + f2;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f
                && f[4] == 10.f && f[5] == 12.f && f[6] == 14.f && f[7] == 16.f;
  }));

  test.add("float8 + __mm256&", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 + f2.get();
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f
                && f[4] == 10.f && f[5] == 12.f && f[6] == 14.f && f[7] == 16.f;
  }));

  test.add("float8 + 1.f", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 + 1;
    return f[0] == 2.f && f[1] == 3.f && f[2] == 4.f && f[3] == 5.f
                && f[4] == 6.f && f[5] == 7.f && f[6] == 8.f && f[7] == 9.f;
  }));

  test.add("float8 += float8", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f += f1;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f
                && f[4] == 10.f && f[5] == 12.f && f[6] == 14.f && f[7] == 16.f;
  }));

  test.add("float8 += __mm256&", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f += f1.get();
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f
                && f[4] == 10.f && f[5] == 12.f && f[6] == 14.f && f[7] == 16.f;
  }));

  test.add("float8 += 1.f", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f += 1.f;
    return f[0] == 2.f && f[1] == 3.f && f[2] == 4.f && f[3] == 5.f
                && f[4] == 6.f && f[5] == 7.f && f[6] == 8.f && f[7] == 9.f;
  }));

  test.add("float8 - float8", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 - f2;
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f
                && f[4] == 0.f && f[5] == 0.f && f[6] == 0.f && f[7] == 0.f;
  }));

  test.add("float8 - __mm256&", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 - f2.get();
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f
                && f[4] == 0.f && f[5] == 0.f && f[6] == 0.f && f[7] == 0.f;
  }));

  test.add("float8 - 1.f", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 - 1.f;
    return f[0] == 0.f && f[1] == 1.f && f[2] == 2.f && f[3] == 3.f
                && f[4] == 4.f && f[5] == 5.f && f[6] == 6.f && f[7] == 7.f;
  }));

  test.add("float8 -= float8", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f -= f1;
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f
                && f[4] == 0.f && f[5] == 0.f && f[6] == 0.f && f[7] == 0.f;
  }));

  test.add("float8 -= __mm256&", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f -= f1.get();
    return f[0] == 0.f && f[1] == 0.f && f[2] == 0.f && f[3] == 0.f
                && f[4] == 0.f && f[5] == 0.f && f[6] == 0.f && f[7] == 0.f;
  }));

  test.add("float8 -= 1.f", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f -= 1.f;
    return f[0] == 0.f && f[1] == 1.f && f[2] == 2.f && f[3] == 3.f
                && f[4] == 4.f && f[5] == 5.f && f[6] == 6.f && f[7] == 7.f;
  }));

  test.add("float8 * float8", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 * f2;
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f
                && f[4] == 25.f && f[5] == 36.f && f[6] == 49.f && f[7] == 64.f;
  }));

  test.add("float8 * __mm256&", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 * f2.get();
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f
                && f[4] == 25.f && f[5] == 36.f && f[6] == 49.f && f[7] == 64.f;
  }));

  test.add("float8 * 2.f", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 * 2.f;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f
                && f[4] == 10.f && f[5] == 12.f && f[6] == 14.f && f[7] == 16.f;
  }));

  test.add("float8 *= float8", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f *= f1;
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f
                && f[4] == 25.f && f[5] == 36.f && f[6] == 49.f && f[7] == 64.f;
  }));

  test.add("float8 *= __mm256&", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f *= f1.get();
    return f[0] == 1.f && f[1] == 4.f && f[2] == 9.f && f[3] == 16.f
                && f[4] == 25.f && f[5] == 36.f && f[6] == 49.f && f[7] == 64.f;
  }));

  test.add("float8 *= 2.f", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f *= 2.f;
    return f[0] == 2.f && f[1] == 4.f && f[2] == 6.f && f[3] == 8.f
                && f[4] == 10.f && f[5] == 12.f && f[6] == 14.f && f[7] == 16.f;
  }));

  test.add("float8 / float8", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 / f2;
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f
                && f[4] == 1.f && f[5] == 1.f && f[6] == 1.f && f[7] == 1.f;
  }));

  test.add("float8 / __mm256&", true, std::function<bool()>([]() {
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f2(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f = f1 / f2.get();
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f
                && f[4] == 1.f && f[5] == 1.f && f[6] == 1.f && f[7] == 1.f;
  }));

  test.add("float8 / 2.f", true, std::function<bool()>([]() {
    simd::float8 f1(2.f, 4.f, 6.f, 8.f, 10.f, 12.f, 14.f, 16.f);
    simd::float8 f = f1 / 2.f;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8 /= float8", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f /= f1;
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f
                && f[4] == 1.f && f[5] == 1.f && f[6] == 1.f && f[7] == 1.f;
  }));

  test.add("float8 /= __mm256&", true, std::function<bool()>([]() {
    simd::float8 f(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    simd::float8 f1(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f);
    f /= f1.get();
    return f[0] == 1.f && f[1] == 1.f && f[2] == 1.f && f[3] == 1.f
                && f[4] == 1.f && f[5] == 1.f && f[6] == 1.f && f[7] == 1.f;
  }));

  test.add("float8 *= 1.f", true, std::function<bool()>([]() {
    simd::float8 f(2.f, 4.f, 6.f, 8.f, 10.f, 12.f, 14.f, 16.f);
    f /= 2.f;
    return f[0] == 1.f && f[1] == 2.f && f[2] == 3.f && f[3] == 4.f
                && f[4] == 5.f && f[5] == 6.f && f[6] == 7.f && f[7] == 8.f;
  }));

  test.add("float8 == float8", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(2.f);
    return f == f2;
  }));

  test.add("float8.equal(float8)", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(2.f);
    simd::float8 res = f.equal(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 != float8", true, std::function<bool()>([]() {
    simd::float8 f(1.f);
    simd::float8 f2(2.f);
    return f != f2;
  }));

  test.add("float8.notEqual(float8)", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(1.f);
    simd::float8 res = f.notEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 > float8", true, std::function<bool()>([]() {
    simd::float8 f(4.f);
    simd::float8 f2(2.f);
    return f > f2;
  }));

  test.add("float8.greater(float8)", true, std::function<bool()>([]() {
    simd::float8 f(4.f);
    simd::float8 f2(2.f);
    simd::float8 res = f.greater(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 >= float8", true, std::function<bool()>([]() {
    simd::float8 f(4.f);
    simd::float8 f2(4.f);
    return f >= f2;
  }));

  test.add("float8.greaterEqual(float8)", true, std::function<bool()>([]() {
    simd::float8 f(4.f);
    simd::float8 f2(4.f);
    simd::float8 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 >= float8", true, std::function<bool()>([]() {
    simd::float8 f(14.f);
    simd::float8 f2(4.f);
    return f >= f2;
  }));

  test.add("float8.greaterEqual(float8)", true, std::function<bool()>([]() {
    simd::float8 f(14.f);
    simd::float8 f2(4.f);
    simd::float8 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8.lesser(float8)", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(4.f);
    simd::float8 res = f.lesser(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 < float8", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(4.f);
    return f < f2;
  }));

  test.add("float8.lesserEqual(float8)", true, std::function<bool()>([]() {
    simd::float8 f(4.f);
    simd::float8 f2(4.f);
    simd::float8 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 <= float8", true, std::function<bool()>([]() {
    simd::float8 f(4.f);
    simd::float8 f2(4.f);
    return f <= f2;
  }));

  test.add("float8 <= float8", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(4.f);
    return f <= f2;
  }));


  test.add("float8.lesserEqual(float8)", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    simd::float8 f2(4.f);
    simd::float8 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("float8 size() == 4", true, std::function<bool()>([]() {
    simd::float8 f(2.f);
    return f.size() == 8;
  }));

  test.run(show);
}

void testDouble2(const utl::BinaryTest::ShowTest & show = utl::BinaryTest::ShowTest::ERRORS) {

  utl::BinaryTest test("Test simd::double2");

  test.add("double2()", true, std::function<bool()>([]() {
    simd::double2 f;
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 0) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("double2(1.)", true, std::function<bool()>([]() {
    simd::double2 f(1.);
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 1.) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("double2(1., 2.)", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2(__m128d&)", true, std::function<bool()>([]() {
    simd::double2 ref(1., 2.);
    simd::double2 f(ref.get());
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2++", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    f++;
    return f[0] == 2. && f[1] == 3.;
  }));

  test.add("double2--", true, std::function<bool()>([]() {
    simd::double2 f(2., 3.);
    f--;
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2 = __m128d&", true, std::function<bool()>([]() {
    simd::double2 ref(1., 2.);
    simd::double2 f = ref.get();
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2 = double2&", true, std::function<bool()>([]() {
    simd::double2 ref(1., 2.);
    simd::double2 f = ref;
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2.set(1., 2.)", true, std::function<bool()>([]() {
    simd::double2 f;
    f.set(1., 2.);
    return f[0] == 2. && f[1] == 1.;
  }));

  test.add("double2.setReversed(1., 2.)", true, std::function<bool()>([]() {
    simd::double2 f;
    f.setReversed(1., 2.);
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2 + double2", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 + f2;
    return f[0] == 2. && f[1] == 4.;
  }));

  test.add("double2 + __m128d&", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 + f2.get();
    return f[0] == 2. && f[1] == 4.;
  }));

  test.add("double2 + 1.", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f = f1 + 1;
    return f[0] == 2. && f[1] == 3.;
  }));

  test.add("double2 += double2", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f += f1;
    return f[0] == 2. && f[1] == 4.;
  }));

  test.add("double2 += __m128d&", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f += f1.get();
    return f[0] == 2. && f[1] == 4.;
  }));

  test.add("double2 += 1.", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    f += 1.;
    return f[0] == 2. && f[1] == 3.;
  }));

  test.add("double2 - double2", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 - f2;
    return f[0] == 0. && f[1] == 0.;
  }));

  test.add("double2 - __m128d&", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 - f2.get();
    return f[0] == 0. && f[1] == 0.;
  }));

  test.add("double2 - 1.", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f = f1 - 1.;
    return f[0] == 0. && f[1] == 1.;
  }));

  test.add("double2 -= double2", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f -= f1;
    return f[0] == 0. && f[1] == 0.;
  }));

  test.add("double2 -= __m128d&", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f -= f1.get();
    return f[0] == 0. && f[1] == 0.;
  }));

  test.add("double2 -= 1.", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    f -= 1.;
    return f[0] == 0. && f[1] == 1.;
  }));

  test.add("double2 * double2", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 * f2;
    return f[0] == 1. && f[1] == 4.;
  }));

  test.add("double2 * __m128d&", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 * f2.get();
    return f[0] == 1. && f[1] == 4.;
  }));

  test.add("double2 * 2.", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f = f1 * 2.;
    return f[0] == 2. && f[1] == 4.;
  }));

  test.add("double2 *= double2", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f *= f1;
    return f[0] == 1. && f[1] == 4.;
  }));

  test.add("double2 *= __m128d&", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f *= f1.get();
    return f[0] == 1. && f[1] == 4.;
  }));

  test.add("double2 *= 1.", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    f *= 2.;
    return f[0] == 2. && f[1] == 4.;
  }));

  test.add("double2 / double2", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 / f2;
    return f[0] == 1. && f[1] == 1.;
  }));

  test.add("double2 / __m128d&", true, std::function<bool()>([]() {
    simd::double2 f1(1., 2.);
    simd::double2 f2(1., 2.);
    simd::double2 f = f1 / f2.get();
    return f[0] == 1. && f[1] == 1.;
  }));

  test.add("double2 / 2.", true, std::function<bool()>([]() {
    simd::double2 f1(2., 4.);
    simd::double2 f = f1 / 2.;
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2 /= double2", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f /= f1;
    return f[0] == 1. && f[1] == 1.;
  }));

  test.add("double2 /= __m128d&", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f1(1., 2.);
    f /= f1.get();
    return f[0] == 1. && f[1] == 1.;
  }));

  test.add("double2 *= 1.", true, std::function<bool()>([]() {
    simd::double2 f(2., 4.);
    f /= 2.;
    return f[0] == 1. && f[1] == 2.;
  }));

  test.add("double2 == double2", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(2.);
    return f == f2;
  }));

  test.add("double2.equal(double2)", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(2.);
    simd::double2 res = f.equal(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 != double2", true, std::function<bool()>([]() {
    simd::double2 f(1., 2.);
    simd::double2 f2(2.);
    return f != f2;
  }));

  test.add("double2.notEqual(double2)", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(1.);
    simd::double2 res = f.notEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 > double2", true, std::function<bool()>([]() {
    simd::double2 f(4.);
    simd::double2 f2(2.);
    return f > f2;
  }));

  test.add("double2.greater(double2)", true, std::function<bool()>([]() {
    simd::double2 f(4.);
    simd::double2 f2(2.);
    simd::double2 res = f.greater(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 >= double2", true, std::function<bool()>([]() {
    simd::double2 f(4.);
    simd::double2 f2(4.);
    return f >= f2;
  }));

  test.add("double2.greaterEqual(double2)", true, std::function<bool()>([]() {
    simd::double2 f(4.);
    simd::double2 f2(4.);
    simd::double2 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 >= double2", true, std::function<bool()>([]() {
    simd::double2 f(14.);
    simd::double2 f2(4.);
    return f >= f2;
  }));

  test.add("double2.greaterEqual(double2)", true, std::function<bool()>([]() {
    simd::double2 f(14.);
    simd::double2 f2(4.);
    simd::double2 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2.lesser(double2)", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(4.);
    simd::double2 res = f.lesser(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 < double2", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(4.);
    return f < f2;
  }));

  test.add("double2.lesserEqual(double2)", true, std::function<bool()>([]() {
    simd::double2 f(4.);
    simd::double2 f2(4.);
    simd::double2 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 <= double2", true, std::function<bool()>([]() {
    simd::double2 f(4.);
    simd::double2 f2(4.);
    return f <= f2;
  }));

  test.add("double2 <= double2", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(4.);
    return f <= f2;
  }));


  test.add("double2.lesserEqual(double2)", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    simd::double2 f2(4.);
    simd::double2 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]);
  }));

  test.add("double2 size() == 2", true, std::function<bool()>([]() {
    simd::double2 f(2.);
    return f.size() == 2;
  }));

  test.run(show);
}

void testDouble4(const utl::BinaryTest::ShowTest & show = utl::BinaryTest::ShowTest::ERRORS) {

  utl::BinaryTest test("Test simd::double4");

  test.add("double4()", true, std::function<bool()>([]() {
    simd::double4 f;
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 0) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("double4(1)", true, std::function<bool()>([]() {
    simd::double4 f(1);
    bool b = true;

    for(std::size_t i = 0; i < f.size(); ++i) {
      if(f[i] != 1) {
        b = false;
        break;
      }
    }
    return b;
  }));

  test.add("double4(1, 2, 3, 4)", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4(__m256d&)", true, std::function<bool()>([]() {
    simd::double4 ref(1, 2, 3, 4);
    simd::double4 f(ref.get());
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4++", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    f++;
    return f[0] == 2 && f[1] == 3 && f[2] == 4 && f[3] == 5;
  }));

  test.add("double4--", true, std::function<bool()>([]() {
    simd::double4 f(2, 3, 4, 5);
    f--;
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4 = __m256d&", true, std::function<bool()>([]() {
    simd::double4 ref(1, 2, 3, 4);
    simd::double4 f = ref.get();
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4 = double4&", true, std::function<bool()>([]() {
    simd::double4 ref(1, 2, 3, 4);
    simd::double4 f = ref;
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4.set(1, 2, 3, 4)", true, std::function<bool()>([]() {
    simd::double4 f;
    f.set(1, 2, 3, 4);
    return f[0] == 4 && f[1] == 3 && f[2] == 2 && f[3] == 1;
  }));

  test.add("double4.setReversed(1, 2, 3, 4)", true, std::function<bool()>([]() {
    simd::double4 f;
    f.setReversed(1, 2, 3, 4);
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4 + double4", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 + f2;
    return f[0] == 2 && f[1] == 4 && f[2] == 6 && f[3] == 8;
  }));

  test.add("double4 + __m256d&", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 + f2.get();
    return f[0] == 2 && f[1] == 4 && f[2] == 6 && f[3] == 8;
  }));

  test.add("double4 + 1", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f = f1 + 1;
    return f[0] == 2 && f[1] == 3 && f[2] == 4 && f[3] == 5;
  }));

  test.add("double4 += double4", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f += f1;
    return f[0] == 2 && f[1] == 4 && f[2] == 6 && f[3] == 8;
  }));

  test.add("double4 += __m256d&", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f += f1.get();
    return f[0] == 2 && f[1] == 4 && f[2] == 6 && f[3] == 8;
  }));

  test.add("double4 += 1", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    f += 1;
    return f[0] == 2 && f[1] == 3 && f[2] == 4 && f[3] == 5;
  }));

  test.add("double4 - double4", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 - f2;
    return f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0;
  }));

  test.add("double4 - __m256d&", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 - f2.get();
    return f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0;
  }));

  test.add("double4 - 1", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f = f1 - 1;
    return f[0] == 0 && f[1] == 1 && f[2] == 2 && f[3] == 3;
  }));

  test.add("double4 -= double4", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f -= f1;
    return f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0;
  }));

  test.add("double4 -= __m256d&", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f -= f1.get();
    return f[0] == 0 && f[1] == 0 && f[2] == 0 && f[3] == 0;
  }));

  test.add("double4 -= 1", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    f -= 1;
    return f[0] == 0 && f[1] == 1 && f[2] == 2 && f[3] == 3;
  }));

  test.add("double4 * double4", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 * f2;
    return f[0] == 1 && f[1] == 4 && f[2] == 9 && f[3] == 16;
  }));

  test.add("double4 * __mm256d&", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 * f2.get();
    return f[0] == 1 && f[1] == 4 && f[2] == 9 && f[3] == 16;
  }));

  test.add("double4 * 2", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f = f1 * 2;
    return f[0] == 2 && f[1] == 4 && f[2] == 6 && f[3] == 8;
  }));

  test.add("double4 *= double4", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f *= f1;
    return f[0] == 1 && f[1] == 4 && f[2] == 9 && f[3] == 16;
  }));

  test.add("double4 *= __mm256d", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f *= f1.get();
    return f[0] == 1 && f[1] == 4 && f[2] == 9 && f[3] == 16;
  }));

  test.add("double4 *= 1", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    f *= 2;
    return f[0] == 2 && f[1] == 4 && f[2] == 6 && f[3] == 8;
  }));

  test.add("double4 / double4", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 / f2;
    return f[0] == 1 && f[1] == 1 && f[2] == 1 && f[3] == 1;
  }));

  test.add("double4 / __m256d&", true, std::function<bool()>([]() {
    simd::double4 f1(1, 2, 3, 4);
    simd::double4 f2(1, 2, 3, 4);
    simd::double4 f = f1 / f2.get();
    return f[0] == 1 && f[1] == 1 && f[2] == 1 && f[3] == 1;
  }));

  test.add("double4 / 2", true, std::function<bool()>([]() {
    simd::double4 f1(2, 4, 6, 8);
    simd::double4 f = f1 / 2;
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4 /= double4", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f /= f1;
    return f[0] == 1 && f[1] == 1 && f[2] == 1 && f[3] == 1;
  }));

  test.add("double4 /= __m256d&", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 3, 4);
    simd::double4 f1(1, 2, 3, 4);
    f /= f1.get();
    return f[0] == 1 && f[1] == 1 && f[2] == 1 && f[3] == 1;
  }));

  test.add("double4 *= 1", true, std::function<bool()>([]() {
    simd::double4 f(2, 4, 6, 8);
    f /= 2;
    return f[0] == 1 && f[1] == 2 && f[2] == 3 && f[3] == 4;
  }));

  test.add("double4 == double4", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(2);
    return f == f2;
  }));

  test.add("double4.equal(double4)", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(2);
    simd::double4 res = f.equal(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 != double4", true, std::function<bool()>([]() {
    simd::double4 f(1, 2, 2, 2);
    simd::double4 f2(2);
    return f != f2;
  }));

  test.add("double4.notEqual(double4)", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(1);
    simd::double4 res = f.notEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 > double4", true, std::function<bool()>([]() {
    simd::double4 f(4);
    simd::double4 f2(2);
    return f > f2;
  }));

  test.add("double4.greater(double4)", true, std::function<bool()>([]() {
    simd::double4 f(4);
    simd::double4 f2(2);
    simd::double4 res = f.greater(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 >= double4", true, std::function<bool()>([]() {
    simd::double4 f(4);
    simd::double4 f2(4);
    return f >= f2;
  }));

  test.add("double4.greaterEqual(double4)", true, std::function<bool()>([]() {
    simd::double4 f(4);
    simd::double4 f2(4);
    simd::double4 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 >= double4", true, std::function<bool()>([]() {
    simd::double4 f(14);
    simd::double4 f2(4);
    return f >= f2;
  }));

  test.add("double4.greaterEqual(double4)", true, std::function<bool()>([]() {
    simd::double4 f(14);
    simd::double4 f2(4);
    simd::double4 res = f.greaterEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4.lesser(double4)", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(4);
    simd::double4 res = f.lesser(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 < double4", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(4);
    return f < f2;
  }));

  test.add("double4.lesserEqual(double4)", true, std::function<bool()>([]() {
    simd::double4 f(4);
    simd::double4 f2(4);
    simd::double4 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 <= double4", true, std::function<bool()>([]() {
    simd::double4 f(4);
    simd::double4 f2(4);
    return f <= f2;
  }));

  test.add("double4 <= double4", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(4);
    return f <= f2;
  }));


  test.add("double4.lesserEqual(double4)", true, std::function<bool()>([]() {
    simd::double4 f(2);
    simd::double4 f2(4);
    simd::double4 res = f.lesserEqual(f2);
    return std::isnan(res[0]) && std::isnan(res[1]) && std::isnan(res[2]) && std::isnan(res[3]);
  }));

  test.add("double4 size() == 4", true, std::function<bool()>([]() {
    simd::double4 f(2);
    return f.size() == 4;
  }));

  test.run(show);
}

#endif /* TESTSIMD_HPP_ */
