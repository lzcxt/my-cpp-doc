#pragma once
#include <string>
#include <fstream>

/**
 * this class used to expand the macro
 */
class MacroExpander {
public:
	std::string process(std::fstream &f);
private:

};