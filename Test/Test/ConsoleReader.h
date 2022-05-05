#pragma once

const char esc = 27;
const char enter = 13;
const char backspace = 8;

class ConsoleReader {
	private:
		std::string buffer;
	public:
		const std::string getData();
		int readConsole(std::string const &prompt);
};
