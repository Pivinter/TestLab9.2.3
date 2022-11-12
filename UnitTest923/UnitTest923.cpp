#include "pch.h"
#include "CppUnitTest.h"
#include "../TestLab9.2.3/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest923
{
	TEST_CLASS(UnitTest923)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = main();
			Assert::AreEqual(t, 0);
		}
	};
}
