#pragma once
#include <iostream>
#include <conio.h>

#include "ConsoleReader.h"

int ConsoleReader::readConsole(std::string const &prompt) {
	reader.debug("Entering console reader");
	std::cout << prompt.c_str() << std::endl;
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

const std::string ConsoleReader::getData() { 
	return buffer; 
};
