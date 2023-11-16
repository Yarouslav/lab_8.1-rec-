#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../lab_8.1(rec)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ut
{
	TEST_CLASS(ut)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str1[] = "abc,def,ghi";
			char str2[] = "abc";
			char str3[] = "a,b,c";

			Assert::AreEqual(2, Count(str1, 0, 0));
			Assert::AreEqual(0, Count(str2, 0, 0));
			Assert::AreEqual(2, Count(str3, 0, 0));
		}
	};
}
