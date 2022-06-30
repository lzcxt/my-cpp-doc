#pragma once

#include <string>

/**
 * this class use to seperate the cpp file into word
 */
class CppFileContent {
public:
	void pushBack(std::string s);
	std::string getWord();
	bool eof();
private:
};
