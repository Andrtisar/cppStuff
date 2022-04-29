#pragma once


class CharOccurrences {
	private:
		const int static possibleChars = 128;
		int charOccurs[possibleChars] = {};
	public:
		static int getPossibleChars();
		void calculateOccurs(int charOccurs[], std::string const &inputLine);
		bool calculateOccursInFile(std::string const &inputFilepath, int charOccurs[]);
		bool outputToFile(std::string const &outputFilePath, int charOccurs[]);
		int * getCharOccurs();
};
