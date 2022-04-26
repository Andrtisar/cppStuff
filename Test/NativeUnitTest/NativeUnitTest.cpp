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
		std::string path = "D:/bruhmoment/Abyss/test.txt";
		int charOccurs[possibleChars] = {};
	public:
		
		TEST_METHOD(TestIfInputPathExists)
		{
			Assert::IsTrue(calculateOccursInFile(path, charOccurs));
		}
		TEST_METHOD(TestIfOutputPathExists)
		{
			Assert::IsTrue(calculateOccursInFile(path, charOccurs));
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
			ConsoleReader reader;
			FAKE_GLOBAL(_getch);
			char testChars[] = {'a', 'b', 8, 13};

			// WHEN_CALLED(_getch()).Return(int(testChars[++i]));
			// int num = TIMES_CALLED(_getch()) - 1;
			//(TIMES_CALLED(_getch()))

			WHEN_CALLED(_getch()).Return(testChars[0]);
			WHEN_CALLED(_getch()).Return(testChars[1]);
			WHEN_CALLED(_getch()).Return(testChars[2]);
			WHEN_CALLED(_getch()).Return(testChars[3]);
			reader.readConsole("test");
			Assert::AreEqual(1, int(reader.getData().length()));
			// I don't want to do this with pointers ;(
		}
		/*TEST_METHOD(TestCalculateOccursInFile)
		{

		}*/
		TEST_METHOD_CLEANUP(TearDown)
		{
			ISOLATOR_CLEANUP();
		}
	};
}
