#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "CharOccurrences.h"


int CharOccurrences::getPossibleChars() {
	return possibleChars; 
};

void CharOccurrences::calculateOccurs(int charOccurs[], std::string const &inputLine) {
	for (int j = 0; j < inputLine.length(); ++j) {
		++charOccurs[int(inputLine[j])];
	}
}


bool CharOccurrences::calculateOccursInFile(std::string const &inputFilepath, int charOccurs[]) {
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


bool CharOccurrences::outputToFile(std::string const &outputFilePath, int charOccurs[]) {
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

int * CharOccurrences::getCharOccurs() {
	return charOccurs;
}
