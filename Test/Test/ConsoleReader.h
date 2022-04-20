#pragma once
#include <iostream>

class ConsoleReader {
	public:
		std::string buffer = "";
		int readConsole() {
			int c;
			do {
				c = getchar();
				if (c != '\n' && c != 27) // tried: 27  char(27)  '^['  'esc'  0x1B  '0x1B'  '\e'  '\x1B'
					buffer += c;
				// can getchar even get esc?
				else
					break;
			} while (true);
			if (c == 27)
				buffer = "";
			return buffer.length();
		};
};
