#pragma once


class CharOccurrences {
	public:
		const int static possibleChars = 128;
		static int getPossibleChars();
		void calculateOccurs(std::string const &inputLine);
		bool calculateOccursInFile(std::string const &inputFilepath);
		bool outputToFile(std::string const &outputFilePath);
	private:
		int charOccurs[possibleChars] = {};
};
