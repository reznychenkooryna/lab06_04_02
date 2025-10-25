#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_04_02/Lab_06_04_02.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { 1.5, -2.3, 4.0, 0.1, 3.3 };
			int n = 5;
			double C = 2.0;

			int result = countLess(arr, n, C);

			int expected = 3;

			Assert::AreEqual(expected, result, L"countLess()");
	};
}
