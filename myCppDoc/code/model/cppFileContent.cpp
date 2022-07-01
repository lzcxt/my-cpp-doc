#include "model/cppFileContent.h"
#include <sstream>
#include <assert.h>
using namespace std;
TOKEN getReserved(string s) {
	if (s == "class") return CLASS_;
	else if (s == "struct") return STRUCT_;
	else if (s == "public") return PUBLIC_;
	else if (s == "private") return PRIVATE_;
	else if (s == "protected") return PROTECTED_;
	else return UNKNOWN_;
}

void CppFileContent::Trans(TOKEN t) {
	if (cur_state == START_STATE_) {
		if (t == SINGLE_QUOTE_) cur_state = SINGLE_QUOTE_STATE;
		else if (t == DOUBLE_QUOTE_) cur_state = DOUBLE_QUOTE_STATE;
		else if (t == CLASS_ || t == STRUCT_) cur_state = CLASS_STATE_1;
	}
	else if (cur_state == SINGLE_QUOTE_STATE) {
		if (t == SINGLE_QUOTE_) cur_state = START_STATE_;
	}
	else if (cur_state == DOUBLE_QUOTE_STATE) {
		if (t == DOUBLE_QUOTE_) cur_state = START_STATE_;
	}
	else if (cur_state == CLASS_STATE_1) {
		if (t == UNKNOWN_) cur_state = CLASS_STATE_2;
		else cur_state = START_STATE_;
	}
	else if (cur_state == CLASS_STATE_2) {
		if (t == COLON_) cur_state = CLASS_STATE_3;
		else cur_state = START_STATE_;
	}
	else if (cur_state == CLASS_STATE_3) {
		if (t == PUBLIC_ || t == PRIVATE_ || t == PROTECTED_) cur_state = CLASS_STATE_3;
		else if (t == UNKNOWN_) cur_state = CLASS_STATE_4;
		else cur_state = START_STATE_;
	}
	else if (cur_state == CLASS_STATE_4) {
		if (t == COMMA_) cur_state = CLASS_STATE_3;
		else cur_state = START_STATE_;
	}
	else assert("invalid state");
}

void CppFileContent::pushBack(string s) {
	stringstream s_in(s, ios_base::in);
	char ch;
	s_in.get(ch);
	Class* cur_class = nullptr;
	while (1) {
		while (isspace(ch)) s_in.get(ch);
		if (ch == ':') Trans(COLON_);
		else if (ch == '\'') Trans(SINGLE_QUOTE_);
		else if (ch == '"') Trans(DOUBLE_QUOTE_);
		else if (isdigit(ch)) {
			while (isdigit(ch)) s_in.get(ch);
			if (ch == '.') {
				s_in.get(ch);
				while (isdigit(ch)) s_in.get(ch);
			}
			Trans(NUMBER_);
		}
		else if (isalpha(ch) || ch == '_') {
			string symbo;
			while (isalpha(ch) || ch == '_') symbo.push_back(ch), s_in.get(ch);
			TOKEN tmp = getReserved(symbo);
			if (tmp == UNKNOWN_) {
				if (cur_state == CLASS_STATE_1) {
					Class &nd = name2class[symbo];
					nd.setName(symbo);
					cur_class = &nd;
				}
				else if (cur_state == CLASS_STATE_3) {
					name2class[symbo].addRelation(Relation(cur_class, inherit));
				}
			}
			Trans(tmp);
		}
	}
}

list<Class> CppFileContent::getClasses() {
	list<Class> cls;
	for (auto item : name2class) cls.push_back(item.second);
	return cls;
}