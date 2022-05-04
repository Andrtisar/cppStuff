#pragma once
#include <iostream>
#include <conio.h>
#include <string>

#include "ConsoleReader.h"

int ConsoleReader::readConsole(std::string const &message) {
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
