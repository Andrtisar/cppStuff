#include <iostream>
#include <fstream>
#include <string>
//#include <stdio.h>


#include "ConsoleReader.h"
#include "CharOccurrences.h"

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




int main() {
	// Logging stuff
	std::string initFileName = "log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);

	log4cpp::Category& root = log4cpp::Category::getRoot();

	log4cpp::Category& main =
		log4cpp::Category::getInstance(std::string("main"));

	main.info("Started app");


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


	CharOccurrences calculateChars;

	std::string outputPath = "debug/output.txt";


	// reads file and calculates char occurs
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
