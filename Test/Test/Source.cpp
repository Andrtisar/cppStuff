#include <iostream>
#include <fstream>
#include <string>
#include "ConsoleReader.h"

const int possibleChars = 128;

void calculateOccurs(int charOccurs[], std::string const &inputLine) {
	for (int j = 0; j < inputLine.length(); ++j) {
		++charOccurs[int(inputLine[j])];
	}
}


bool calculateOccursInFile(std::string const &inputFilepath, int charOccurs[]) {
	std::string inputLine;
	std::ifstream input;
	input.open(inputFilepath);
	if (!input.is_open()) {
		return false;
	}
	while (!input.eof()) {
		getline(input, inputLine);

		// calculates the number of occurrences of each unique symbol
		calculateOccurs(charOccurs, inputLine);
	}
	input.close();
	return true;
}


bool outputToFile(std::string const &outputFilePath, int charOccurs[]) {
	std::ofstream output;
	output.open(outputFilePath);
	if (!output.is_open()) {
		return false;
	}

	
	for (int i = 0; i < possibleChars; ++i) {
		if (charOccurs[i]) {
			output << char(i) << ": " << charOccurs[i] << std::endl;
		}
	}
	output.close();
	return true;
}


int main() {
	// gets the path to file as an input from command line
	std::string inputPath;
	ConsoleReader reader;
	std::string message = "Input file path:";
	if (reader.readConsole(message)) {
		inputPath = reader.getData();
	}
	else {
		return 0;
	}
	std::cout << std::endl;

	
	int charOccurs[possibleChars] = {};
	std::string outputPath = "debug/output.txt";


	// reads file and calculates char occurs
	if (calculateOccursInFile(inputPath, charOccurs)) {
		if (outputToFile(outputPath, charOccurs)) {
			//make into log
			std::cout << "Creating " << outputPath << " file with char occurences in input file" << std::endl;
		}
		else {
			std::cout << "Could not create the file with a path " << outputPath << std::endl;
		}
	}
	else {
		std::cout << "Could not open the file with a path " << inputPath << std::endl;
	}
	return 0;
}
