#pragma once

#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Category.hh>

const char esc = 27;
const char enter = 13;
const char backspace = 8;

class ConsoleReader {
	private:
		std::string buffer = "";

		log4cpp::Category& reader =
			log4cpp::Category::getInstance(std::string("consoleReader"));
	public:
		const std::string getData();
		int readConsole(std::string const &prompt);
};
