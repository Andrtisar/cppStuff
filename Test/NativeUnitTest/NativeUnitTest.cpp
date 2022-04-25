#include "pch.h"
#include "CppUnitTest.h"
#include "../Test/ConsoleReader.cpp"
#include "../Test/Source.cpp"
#include <iostream>

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
		TEST_METHOD(TestCalculateOccursInLine) 
		{
			int charOccurs[possibleChars] = {};
			std::string line = "aaA  ";
			calculateOccurs(charOccurs, line);
			Assert::AreEqual(2, charOccurs[int('a')]);
		}
	};
}
