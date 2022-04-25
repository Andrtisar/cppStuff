#pragma once
#include <iostream>
#include <conio.h>

class ConsoleReader {
	public:
		std::string buffer = "";
		int readConsole() {
			char esc = 27;
			char enter = 13;
			char backspace = 8;
			char c;
			do {
				c = _getch();
				if (c != enter && c != esc) {
					if (c != backspace)
						buffer += c;
					else
						buffer.pop_back();
					_putch(c);
				}
				// can getchar even get esc?
				else
					break;
			} while (true);
			if (c == esc)
				buffer = "";
			return buffer.length();
		};
};
