#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "CharOccurrences.h"


void CharOccurrences::calculateOccurs(std::string const &inputLine, int charOccurs[]) {
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
		calculateOccurs(inputLine, charOccurs);
	}
	input.close();
	return true;
}



// This was a bad idea, wasn't it?
// Now I just have two pretty much identical pairs of methods
// "what if I change one but forget to update another?"
// Well, that is a fair point, however
// ... I literally have no idea how to do it in a different way
// ... also I just realised that this means I am technically not testing all methods
// and use different for testing and actually running the app.
// Yeah, this is just a mess at best, a crime against humanity at worst.
void CharOccurrences::calculateOccurs(std::string const &inputLine) {
	for (int j = 0; j < inputLine.length(); ++j) {
		++charOccurs[int(inputLine[j])];
	}
}


bool CharOccurrences::calculateOccursInFile(std::string const &inputFilepath) {
	std::string inputLine;
	std::ifstream input;
	input.open(inputFilepath);
	if (!input.is_open()) {
		return false;
	}
	while (!input.eof()) {
		getline(input, inputLine);

		// calculates the number of occurrences of each unique symbol
		calculateOccurs(inputLine);
	}
	input.close();
	return true;
}


bool CharOccurrences::outputToFile(std::string const &outputFilePath) {
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
