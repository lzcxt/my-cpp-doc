#pragma once

#include <string>
#include "common.h"
#include <queue>
#include <map>


enum TOKEN {
	COLON_,
	COMMA_,
	DIVIDE_,
	MULTIPLY_,
	SINGLE_QUOTE_,
	DOUBLE_QUOTE_,
	LEFT_BRACE_,
	RIGHT_BRACE_,
	LEFT_COMMENT_,
	RIGHT_COMMENT_,
	NUMBER_,
	CLASS_,
	STRUCT_,
	PUBLIC_,
	PRIVATE_,
	PROTECTED_,
	EOF_,
	UNKNOWN_,
};

enum STATE {
	START_STATE,
	SINGLE_QUOTE_STATE,
	DOUBLE_QUOTE_STATE,
	COMMENT_STATE,
	CLASS_STATE_1,
	CLASS_STATE_2,
	CLASS_STATE_3,
	CLASS_STATE_4
};

/**
 * this class use to seperate the cpp file into word
 */
class CppFileContent {
public:
	CppFileContent() : cur_state(START_STATE) {}
	void pushBack(std::string s);
	std::list<Class> getClasses();
private:
	void Trans(TOKEN t);
	std::map<std::string, Class> name2class;
	STATE cur_state;
};
