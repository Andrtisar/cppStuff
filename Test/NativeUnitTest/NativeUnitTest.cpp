#include "pch.h"
#include "CppUnitTest.h"
#include "../Test/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{
	TEST_CLASS(NativeUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
			Assert::AreNotEqual(1, 2);
		}
	};
}
