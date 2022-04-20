#include <iostream>
#include <fstream>
#include <string>

void calculateOccurs(int arr[], std::string line) {
	for (int j = 0; j < line.length(); ++j) {
		++arr[int(line[j])];
	}
}


// void(*fileFunction)(int[], std::string) -> passing a function as an argument
// there is no way that I could come up with this
// and I don't really see a reason to use this
// so I'm just not going to

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
	for (int i = 0; i < 128; ++i) {
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
	std::cout << "Input file path:\n";
	getline(std::cin, path);
	// TODO - custom getline

	//path = "Debug/test.txt";

	
	// create an array filled with 0
	int charOccurs[128];
	for (int i = 0; i < 128; ++i) {
		charOccurs[i] = 0;
	}

	// ASCII chars have numbers from 0 to 127, but only <32, 126> are printable,
	// 32 - space, 126 - tilde

	
	// reads the text from file
	if (calculateOccursInFile(path, charOccurs)) {
		// outputs to another file
		outputToFile("output.txt", charOccurs);
	}
}
