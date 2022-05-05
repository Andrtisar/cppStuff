#include "pch.h"
#include "CppUnitTest.h"
#include "IncludesForUnitTest.h"

#include <isolator.h>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTestForMain
{
	TEST_CLASS(MainTests)
	{
		CharOccurrences calculateChars;
		std::string path = "D:/bruhmoment/Abyss/test.txt";

	public:
		
		TEST_METHOD(TestIfInputPathExists)
		{
			Assert::IsTrue(calculateChars.calculateOccursInFile(path));
		}
		TEST_METHOD(TestIfOutputPathExists)
		{
			Assert::IsTrue(calculateChars.calculateOccursInFile(path));
		}
		TEST_METHOD(TestCalculateOccursInLine) 
		{
			static const int possibleCharsForTest = calculateChars.possibleChars;
			int charOccurs[possibleCharsForTest] = {};
			std::string line = "aaA  ";
			calculateChars.calculateOccurs(line, charOccurs);
			Assert::AreEqual(2, charOccurs[int('a')]);
		}
		TEST_METHOD(TestConsoleReader)
		{
			// ConsoleReader* reader = FAKE<ConsoleReader>();
			ConsoleReader reader;
			FAKE_GLOBAL(_getch);
			char testChars[] = {'a', 'b', reader.backspace, 'c', reader.enter};


			// int * timesCalled = TIMES_CALLED(_getch());
			// WHEN_CALLED(_getch()).Return(testChars[int(timesCalled)]);
			// why doesn't this work ;(


			WHEN_CALLED(_getch()).Return(testChars[0]);
			WHEN_CALLED(_getch()).Return(testChars[1]);
			WHEN_CALLED(_getch()).Return(testChars[2]);
			WHEN_CALLED(_getch()).Return(testChars[3]);
			WHEN_CALLED(_getch()).Return(testChars[4]);
			reader.readConsole("testing some letters with backspace and enter");
			Assert::AreEqual(2, int(reader.getData().length()));


			WHEN_CALLED(_getch()).Return(reader.esc);
			reader.readConsole("testing escape");
			Assert::AreEqual(0, int(reader.getData().length()));
		}
		 TEST_METHOD(TestCalculateOccursInFile)
		{
			// you can't fake ifstream with this framework :/
			 std::ofstream testFile;
			 std::string testPath = "testFile.txt";
			 std::string testData = "testData";
			 testFile.open(testPath);
			 testFile << testData;
			 Assert::IsTrue(testFile.is_open());
			 testFile.close();

			 // int possibleCharsForTest = calculateChars.getPossibleChars();

			 static const int possibleCharsForTest = calculateChars.possibleChars;

			 int manualCharOccurs[possibleCharsForTest] = {};
			 int testCharOccurs[possibleCharsForTest] = {};
			 calculateChars.calculateOccurs(testData, manualCharOccurs);
			 Assert::IsTrue(calculateChars.calculateOccursInFile(testPath, testCharOccurs));


			 for (int i = 0; i < possibleCharsForTest; ++i) {
				 Assert::AreEqual(manualCharOccurs[i], testCharOccurs[i]);
			 }
			 // comparing arrays doesn't work, have to compare each element

			 
			 remove(testPath.c_str());
		}
		TEST_METHOD_CLEANUP(TearDown)
		{
			ISOLATOR_CLEANUP();
		}
	};
}
