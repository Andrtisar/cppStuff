#pragma once
#include <iostream>
#include <conio.h>

class ConsoleReader {
	public:
		std::string buffer = "";
		int readConsole() {
			int c;
			do {
				c = getch();
				if (c != 13 && c != 27) {
					buffer += c;
					putch(c);
				}
				// can getchar even get esc?
				else
					break;
			} while (true);
			if (c == 27)
				buffer = "";
			return buffer.length();
		};
};
