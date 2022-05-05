#include "pch.h"
#include "CppUnitTest.h"
#include "../Test/ConsoleReader.cpp"
#include "../Test/Source.cpp"
#include <isolator.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTestForMain
{
	TEST_CLASS(MainTests)
	{
		int charOccurs[possibleChars] = {};
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



			Assert::IsTrue(calculateOccursInFile(path, charOccurs));
			remove(path.c_str());
		}
		TEST_METHOD(TestCalculateOccursInLine) 
		{
			std::string line = "aaA  ";
			calculateOccurs(charOccurs, line);
			Assert::AreEqual(2, charOccurs[int('a')]);
		}
		TEST_METHOD(TestConsoleReader)
		{
			// ConsoleReader* reader = FAKE<ConsoleReader>();
			FAKE_GLOBAL(_getch);
			char testChars[] = {'a', 'b', backspace, 'c', enter};


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
			WHEN_CALLED(_getch()).Return(esc);
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


			 int manualCharOccurs[possibleChars] = {};
			 int testCharOccurs[possibleChars] = {};
			 calculateOccurs(manualCharOccurs, testData);
			 Assert::IsTrue(calculateOccursInFile(testPath, testCharOccurs));


			 /*for (int i = 0; i < possibleChars; ++i) {
				 Assert::AreEqual(manualCharOccurs[i], testCharOccurs[i]);
			 }*/
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
