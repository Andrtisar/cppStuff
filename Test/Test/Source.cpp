#include <iostream>
#include <fstream>
#include <string>

const int possibleChars = 127; // technically 128 but shush

void calculateOccurs(int arr[], std::string line) {
	for (int j = 0; j < line.length(); ++j) {
		++arr[int(line[j])];
	}
}


int main() {
	// gets the path to file as an input from command line

	std::string path;
	std::ifstream input;


	do {
		std::cout << "Input file path, or write ! to exit:\n";
		getline(std::cin, path);
		if (path == "!") return 0;
		input.open(path);
	} while (!input.is_open());

	//path = "Debug/test.txt";


	// create an array filled with 0

	int charOccurs[possibleChars];
	for (int i = 0; i < possibleChars; ++i) {
		charOccurs[i] = 0;
	}
	// ASCII chars have numbers from 0 to 127, but only <32, 126> are printable,
	// 32 - space, 126 - tilde


	// reads the text from file

	std::string line;
	while (!input.eof()) {
		getline(input, line);
		// std::cout << line << std::endl;

		// calculates the number of occurrences of each unique symbol
		calculateOccurs(charOccurs, line);
	}
	input.close();

	// outputs to another file

	std::ofstream output;
	output.open("output.txt");

	std::cout << "Creating output.txt file with char occurences in input file\n";
	for (int i = 0; i < possibleChars; ++i) {
		if (charOccurs[i]) {
			// std::cout << char(i) << ": " << charOccurs[i] << std::endl;
			output << char(i) << ": " << charOccurs[i] << std::endl;
		}
	}
  
	output.close();
}