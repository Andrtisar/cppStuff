#pragma once

#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Category.hh>

class ConsoleReader {
	private:
		std::string buffer = "";
		log4cpp::Category& reader =
			log4cpp::Category::getInstance(std::string("consoleReader"));
	public:
		const char esc = 27;
		const char enter = 13;
		const char backspace = 8;
		const std::string getData();
		int readConsole(const char * prompt);
};
