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
			int charOccurs[possibleChars] = {};
			std::string path = "D:/bruhmoment/Abyss/ToDo.txt";
			Assert::IsTrue(calculateOccursInFile(path, charOccurs));
		}
	};
}
