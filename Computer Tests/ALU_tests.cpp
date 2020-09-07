#include "stdafx.h"
#include "CppUnitTest.h"

#include "ALU.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComputerTests
{		
	TEST_CLASS(ALU_negate_tests)
	{
	public:
		TEST_METHOD(negate_positive_1)
		{
			U32 n = 1;
			U32 r = ALU::negate(n);

			Assert::IsTrue(-n == r);
		}

		TEST_METHOD(negate_negative_1)
		{
			U32 n = -1;
			U32 r = ALU::negate(n);

			Assert::IsTrue(-n == r);
		}

		TEST_METHOD(negate_any)
		{
			I16 n = 32;
			I16 r = ALU::negate(n);

			Assert::IsTrue(-n == r);
		}
	};

	TEST_CLASS(ALU_add_tests)
	{
	public:
		
		TEST_METHOD(add_positive)
		{
			U32 a = 1;
			U16 b = 42;
			bit carry = 0;
			U32 r = ALU::add(a, b, carry);

			Assert::AreEqual(a + b, r);
			Assert::IsTrue(carry == 0);
		}

		TEST_METHOD(add_negative)
		{
			U32 a = 1;
			I16 b = -42;
			bit carry = 0;
			U32 r = ALU::add(a, b, carry);

			Assert::AreEqual(a + b, r);
			Assert::IsTrue(carry == 0);
		}

		TEST_METHOD(add_overflow)
		{
			U32 a = 1;
			U32 b = -1;
			bit carry = 0;
			U32 r = ALU::add(a, b, carry);

			Assert::IsTrue(r == 0);
			Assert::IsTrue(carry == 1);
		}

		TEST_METHOD(add_with_carry)
		{
			U32 a = 1;
			U32 b = 1;
			bit carry = 1;
			U32 r = ALU::add(a, b, carry);

			Assert::AreEqual(a + b + 1, r);
			Assert::IsTrue(carry == 0);
		}
	};

	TEST_CLASS(ALU_multiply_tests)
	{
	public:
		TEST_METHOD(multiply_positive)
		{
			U16 a = 37;
			U16 b = 12;
			U16 r = ALU::multiply(a, b);

			Assert::IsTrue(a * b == r);
		}

		TEST_METHOD(multiply_negative)
		{
			I16 a = -45;
			I16 b = 11;
			I16 r = ALU::multiply(a, b);

			Assert::IsTrue(a * b == r);
		}

		TEST_METHOD(multiply_overflow)
		{
			I16 a = 25648;
			I16 b = 54621;
			I16 r = ALU::multiply(a, b);

			Assert::IsTrue(I16(a * b) == r);
		}
	};

	TEST_CLASS(ALU_divide_tests)
	{
	public:

		TEST_METHOD(divide_positive)
		{
			U32 n = 64;
			U16 d = 16;
			U32 q, r;
			bit divByZero;
			ALU::unsigned_divide(n, d, q, r, divByZero);

			Assert::IsTrue(q == (n / d));
			Assert::IsTrue(r == (n % d));
			Assert::IsFalse(divByZero);
		}

		TEST_METHOD(divide_by_zero)
		{
			U32 n = 61;
			U16 d = 0;
			U32 q, r;
			bit divByZero;
			ALU::unsigned_divide(n, d, q, r, divByZero);

			Assert::IsTrue(divByZero);
		}
	};
}