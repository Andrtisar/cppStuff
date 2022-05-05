#pragma once
#include <iostream>
#include <fstream>
#include <string>
//#include <stdio.h>

#include "ConsoleReader.h"
#include "CharOccurrences.h"

#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Category.hh>


int main() {
	// Logging stuff
	std::string initFileName = "log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);

	log4cpp::Category& root = log4cpp::Category::getRoot();

	log4cpp::Category& main =
		log4cpp::Category::getInstance(std::string("main"));

	main.info("Started app");


	std::string inputPath;
	ConsoleReader reader;
	if (reader.readConsole("Input file path:")) {
		inputPath = reader.getData();
	}
	else {
		main.info("Exited from app");
		log4cpp::Category::shutdown();
		return 0;
	}
	std::cout << std::endl;

	CharOccurrences calculateChars;

	std::string outputPath = "Output/output.txt";

	if (calculateChars.calculateOccursInFile(inputPath)) {
		if (calculateChars.outputToFile(outputPath)) {
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
