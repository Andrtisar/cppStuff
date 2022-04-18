#include <iostream>
#include <fstream>
#include <string>

void calculateOccurs(int arr[], std::string line) {
	for (int j = 0; j < line.length(); ++j) {
		++arr[int(line[j])] ;
	}
}


int main() {
	// gets the path to file as an input from command line

	std::string path;
	std::ifstream input;


	do {
		std::cout << "Input file path:\n";
		getline(std::cin, path);
		input.open(path);
	} while (!input.is_open());
	
	//path = "Debug/test.txt";


	// create an array filled with 0

	int charOccurs[255];
	for (int i = 0; i < 255; ++i) {
		charOccurs[i] = 0;
	}

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
	for (int i = 0; i < 255; ++i) {
		if (charOccurs[i] != 0) {
			// std::cout << char(i) << ": " << charOccurs[i] << std::endl;
			output << char(i) << ": " << charOccurs[i] << std::endl;
		}
	}

	output.close();
}