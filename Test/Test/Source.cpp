#include <iostream>
#include <fstream>
#include <string>
#include "ConsoleReader.h"

const int possibleChars = 128;

void calculateOccurs(int arr[], std::string line) {
	for (int j = 0; j < line.length(); ++j) {
		++arr[int(line[j])];
	}
}


bool calculateOccursInFile(std::string path, int arr[]) {
	std::string line;
	std::ifstream input;
	input.open(path);
	if (!input.is_open()) {
		std::cout << "Could not open the file with a path " << path;
		return false;
	}
	while (!input.eof()) {
		getline(input, line);
		// std::cout << line << std::endl;

		// calculates the number of occurrences of each unique symbol
		calculateOccurs(arr, line);
	}
	input.close();
	return true;
}
// so this is not really reusable, and I'm not sure if that can be fixed, or if it even is necessary


void outputToFile(std::string outputPath, int arr[]) {
	std::ofstream output;
	output.open(outputPath);

	std::cout << "Creating output.txt file with char occurences in input file\n";
	for (int i = 0; i < possibleChars; ++i) {
		if (arr[i]) {
			// std::cout << char(i) << ": " << charOccurs[i] << std::endl;
			output << char(i) << ": " << arr[i] << std::endl;
		}
	}
	output.close();
}


int main() {
	// gets the path to file as an input from command line
	std::string path;
	ConsoleReader reader;
	std::cout << "Input file path:\n";
	if (reader.readConsole()) {
		path = reader.buffer;
	}
	else {
		exit(-1);
	}
	std::cout << "\n";
	//path = "Debug/test.txt";

	
	// create an array filled with 0
	int charOccurs[possibleChars];
	for (int i = 0; i < possibleChars; ++i) {
		charOccurs[i] = 0;
	}

	
	// reads the text from file
	if (calculateOccursInFile(path, charOccurs)) {
		// outputs to another file
		outputToFile("output.txt", charOccurs);
	}
}
