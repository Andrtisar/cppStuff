#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


#include "ConsoleReader.h"

#include <log4cpp/Portability.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/NDC.hh>


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
	// Logging stuff
	std::string initFileName = "log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);

	log4cpp::Category& root = log4cpp::Category::getRoot();

	log4cpp::Category& main =
		log4cpp::Category::getInstance(std::string("main"));

	main.info("Started app");

	/*sub2.debug("Hiding solar panels");
	sub2.error("Solar panels are blocked");
	sub2.debug("Applying protective shield");
	sub2.warn("Unfolding protective shield");
	sub2.info("Solar panels are shielded");*/


	// gets the path to file as an input from command line
	std::string inputPath;
	ConsoleReader reader;
	std::string message = "Input file path:";
	if (reader.readConsole(message)) {
		inputPath = reader.getData();
	}
	else {
		main.info("Exited from app");
		log4cpp::Category::shutdown();
		return 0;
	}
	std::cout << std::endl;


	int charOccurs[possibleChars] = {};
	std::string outputPath = "debug/output.txt";


	// reads file and calculates char occurs
	if (calculateOccursInFile(inputPath, charOccurs)) {
		if (outputToFile(outputPath, charOccurs)) {
			main.info("Creating " + outputPath + " file with char occurences in input file.");
		}
		else {
			main.error("Could not create the file with a path " + outputPath);
		}
	}
	else {
		main.error("Could not open the file with a path " + inputPath);
	}
	log4cpp::Category::shutdown();
	return 0;
}
