#include "pch.h"
#include "CppUnitTest.h"
#include "../Test/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTestForMain
{
	TEST_CLASS(MainTests)
	{
	public:
		
		TEST_METHOD(TestIfPathExists)
		{
			int charOccurs[possibleChars];
			for (int i = 0; i < possibleChars; ++i) {
				charOccurs[i] = 0;
			}
			Assert::IsFalse(calculateOccursInFile("randompath.txt", {}));
			Assert::IsTrue(calculateOccursInFile("D:/bruhmoment/Abyss/ToDo.txt", charOccurs));
		}
	};
}
