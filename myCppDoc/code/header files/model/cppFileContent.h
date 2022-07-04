#pragma once

#include <string>
#include "common/common.h"
#include <queue>
#include <memory>
#include <map>


enum TOKEN {
	COLON_,
	SEMICOLON_,
	COMMA_,
	BACKWARD_SLASH_,
	BACKWARD_SLASH_WITH_CHARACTOR_,
	DIVIDE_,
	MULTIPLY_,
	SINGLE_QUOTE_,
	DOUBLE_QUOTE_,
	LEFT_BRACE_,
	RIGHT_BRACE_,
	QUESTION_MARK_,
	LEFT_COMMENT_,
	RIGHT_COMMENT_,
	LOGICAL_AND_,
	ARITHMATIC_AND_,
	LOGICAL_OR_,
	ARITHMATIC_OR_,
	LESS_,
	SINGLE_EQUAL_,
	DOUBLE_EQUAL_,
	LESS_EQUAL_,
	LEFT_PARENTHESES_,
	RIGHT_PARENTHESES_,
	GREATER_,
	GREATER_EQUAL_,
	NUMBER_,
	CLASS_,
	STRUCT_,
	PUBLIC_,
	PRIVATE_,
	PROTECTED_,
	TEMPLATE_,
	UNKNOWN_WORD_,
	UNKNOWN_SYMBOL_,
	EOF_,
};

/**
 * this class use to seperate the cpp file into word
 */
class CppFileContent {
public:
	CppFileContent() {}
	void pushBack(std::string s);
	const std::list<shared_ptr<Class>>& getClasses();
private:
	std::map<std::string, shared_ptr<Class> > name2class;
};
