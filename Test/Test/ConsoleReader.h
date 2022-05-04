#pragma once

const char esc = 27;
const char enter = 13;
const char backspace = 8;

class ConsoleReader {
	private:
		std::string buffer = "";

		log4cpp::Category& reader =
			log4cpp::Category::getInstance(std::string("consoleReader"));
	public:
		std::string getData();
		int readConsole(std::string const &message);
};
