#include <iostream>
#include <conio.h>
#include "ConsoleReader.h"

int ConsoleReader::readConsole(std::string const &message) {
	std::cout << message.c_str() << std::endl;
	// make into log
	char c;
	c = _getch();
	while (c != enter && c != esc) {
		if (c != backspace)
			buffer += c;
		else
			buffer.pop_back();
		_putch(c);
		c = _getch();
	}
	if (c == esc)
		buffer.clear();
	return buffer.length();
};

std::string ConsoleReader::getData() { 
	return buffer; 
};
