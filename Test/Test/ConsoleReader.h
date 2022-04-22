#pragma once
#include <iostream>
#include <conio.h>

class ConsoleReader {
	public:
		std::string buffer = "";
		int readConsole() {
			char esc = 27;
			char enter = 13;
			int c;
			do {
				c = getch();
				if (c != enter && c != esc) {
					buffer += c;
					putch(c);
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
