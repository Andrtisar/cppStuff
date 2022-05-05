#include "pch.h"
#include "CppUnitTest.h"
#include "IncludesForUnitTest.h"

#include <isolator.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTestForMain
{
	TEST_CLASS(MainTests)
	{
		CharOccurrences calculateChars;
		ConsoleReader reader;
    
	public:
		
		TEST_METHOD(TestIfPathExists)
		{
			std::ofstream testFile;
			std::string path = "testFile.txt";
			std::string testData = "testData";
			testFile.open(path);
			testFile << testData;
			Assert::IsTrue(testFile.is_open());
			testFile.close();


			Assert::IsTrue(calculateChars.calculateOccursInFile(path));
			remove(path.c_str());
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
			FAKE_GLOBAL(_getch);
			char testChars[] = {'a', 'b', reader.backspace, 'c', reader.enter};


			WHEN_CALLED(_getch()).Return(testChars[0]);
			WHEN_CALLED(_getch()).Return(testChars[1]);
			WHEN_CALLED(_getch()).Return(testChars[2]);
			WHEN_CALLED(_getch()).Return(testChars[3]);
			WHEN_CALLED(_getch()).Return(testChars[4]);
			reader.readConsole("testing some letters with backspace and enter");

			std::string receivedBuffer = reader.getData();


			// Expected output: "ac"
			Assert::AreEqual(2, int(receivedBuffer.length()));
			Assert::AreEqual('a', receivedBuffer[0]);
			Assert::AreEqual('c', receivedBuffer[1]);
		}
		TEST_METHOD(TestConsoleReaderEsc)
		{
			FAKE_GLOBAL(_getch);
			WHEN_CALLED(_getch()).Return(reader.esc);
			reader.readConsole("testing escape");
			Assert::AreEqual(0, int(reader.getData().length()));
		}
		TEST_METHOD(TestCalculateOccursInFile)
		{
			 std::ofstream testFile;
			 std::string testPath = "testFile.txt";
			 std::string testData = "testData";
			 testFile.open(testPath);
			 testFile << testData;
			 Assert::IsTrue(testFile.is_open());
			 testFile.close();


			 static const int possibleCharsForTest = calculateChars.possibleChars;

			 int manualCharOccurs[possibleCharsForTest] = {};
			 int testCharOccurs[possibleCharsForTest] = {};
			 calculateChars.calculateOccurs(testData, manualCharOccurs);
			 Assert::IsTrue(calculateChars.calculateOccursInFile(testPath, testCharOccurs));

			 
			 Assert::IsTrue(std::equal(
				 std::begin(manualCharOccurs), std::end(manualCharOccurs), std::begin((testCharOccurs))
			 ));
			 
			 remove(testPath.c_str());
		}
		TEST_METHOD_CLEANUP(TearDown)
		{
			ISOLATOR_CLEANUP();
		}
	};
}
