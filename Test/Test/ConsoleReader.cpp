#pragma once
#include <iostream>
#include <conio.h>
#include <string>

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

int ConsoleReader::readConsole(std::string const &message) {
	log4cpp::Category& reader =
		log4cpp::Category::getInstance(std::string("consoleReader"));

	reader.debug("Entering console reader");
	std::cout << message.c_str() << std::endl;
	char c;
	c = _getch();
	reader.debug("Received char: " + std::to_string(c));
	while (c != enter && c != esc) {
		if (c != backspace)
			buffer += c;
		else
			buffer.pop_back();
		_putch(c);
		c = _getch();
		reader.debug("Received char: " + std::to_string(c));
	}
	if (c == esc)
		buffer.clear();
	reader.debug("Exiting console reader");
	return buffer.length();
};

std::string ConsoleReader::getData() { 
	return buffer; 
};
