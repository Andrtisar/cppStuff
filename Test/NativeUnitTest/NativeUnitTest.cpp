#include "pch.h"
#include "CppUnitTest.h"
#include "../Test/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{
	TEST_CLASS(NativeUnitTest)
	{
	public:
		
		TEST_METHOD(TestIfPathExists)
		{
			Assert::IsFalse(calculateOccursInFile("randompath.txt", {}));
		}
	};
}
