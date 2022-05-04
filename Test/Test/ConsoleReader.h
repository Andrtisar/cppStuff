#pragma once


class ConsoleReader {
	private:
		std::string buffer = "";
	public:
		const char esc = 27;
		const char enter = 13;
		const char backspace = 8;
		std::string getData();
		int readConsole(const char * message);
};
