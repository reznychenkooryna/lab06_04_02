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
			double arr[] = { 1.5, -2.3, 3.0, 0.7 };
			double C = 1.0;

			int expected = 2;

			int actual = countLess(arr, 4, C);

			Assert::AreEqual(expected, actual);
		}
	};
}
