#include "model/cppFileContent.h"
#include <sstream>
#include <assert.h>
#include "cmFunctions.h"
using namespace std;
TOKEN getReserved(string s) {
	if (s == "class") return CLASS_;
	else if (s == "struct") return STRUCT_;
	else if (s == "public") return PUBLIC_;
	else if (s == "private") return PRIVATE_;
	else if (s == "protected") return PROTECTED_;
	else return UNKNOWN_;
}

fstream db_err("Model_ErrorLog.txt", fstream::out);
fstream db_out("Model_Output.txt", fstream::out);

void CppFileContent::Trans(TOKEN t) {
	if (cur_state == START_STATE) {
		if (t == SINGLE_QUOTE_) cur_state = SINGLE_QUOTE_STATE;
		else if (t == DOUBLE_QUOTE_) cur_state = DOUBLE_QUOTE_STATE;
		else if (t == CLASS_ || t == STRUCT_) cur_state = CLASS_STATE_1;
		else if (t == LEFT_COMMENT_) cur_state = COMMENT_STATE;
	}
	else if (cur_state == SINGLE_QUOTE_STATE) {
		if (t == SINGLE_QUOTE_) cur_state = START_STATE;
	}
	else if (cur_state == DOUBLE_QUOTE_STATE) {
		if (t == DOUBLE_QUOTE_) cur_state = START_STATE;
	}
	else if (cur_state == COMMENT_STATE) {
		if (t == RIGHT_COMMENT_) cur_state = START_STATE;
	}
	else if (cur_state == CLASS_STATE_1) {
		if (t == UNKNOWN_) cur_state = CLASS_STATE_2;
		else cur_state = START_STATE;
	}
	else if (cur_state == CLASS_STATE_2) {
		if (t == COLON_) cur_state = CLASS_STATE_3;
		else cur_state = START_STATE;
	}
	else if (cur_state == CLASS_STATE_3) {
		if (t == PUBLIC_ || t == PRIVATE_ || t == PROTECTED_) cur_state = CLASS_STATE_3;
		else if (t == UNKNOWN_) cur_state = CLASS_STATE_4;
		else cur_state = START_STATE;
	}
	else if (cur_state == CLASS_STATE_4) {
		if (t == COMMA_) cur_state = CLASS_STATE_3;
		else cur_state = START_STATE;
	}
	else assert("invalid state");
	db_err << "by token " << t << " go to " << cur_state << endl;
}

void CppFileContent::pushBack(string s) {
	stringstream s_in(s + string(1, EOF), ios_base::in);
	char ch;
	s_in.get(ch);
	cur_state = START_STATE;
	Class* cur_class = nullptr;
	while (1) {
		while (isspace(ch)) s_in.get(ch);
		db_err << ch << endl;
		if (ch == ':') Trans(COLON_), s_in.get(ch);
		else if (ch == '\'') Trans(SINGLE_QUOTE_), s_in.get(ch);
		else if (ch == '"') Trans(DOUBLE_QUOTE_), s_in.get(ch);
		else if (ch == '{') Trans(LEFT_BRACE_), s_in.get(ch);
		else if (ch == '}') Trans(RIGHT_BRACE_), s_in.get(ch);
		else if (ch == ',') Trans(COMMA_), s_in.get(ch);
		else if (ch == '/') {
			s_in.get(ch);
			if (ch == '*') {
				Trans(LEFT_COMMENT_);
				s_in.get(ch);
			}
			else {
				Trans(DIVIDE_);
			}
		}
		else if (ch == '*') {
			s_in.get(ch);
			if (ch == '/') {
				Trans(RIGHT_COMMENT_);
				s_in.get(ch);
			} 
			else {
				Trans(MULTIPLY_);
			}
		}
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
					db_err << "find class: " << symbo << endl;
					Class &nd = name2class[symbo];
					nd.setName(symbo);
					cur_class = &nd;
				}
				else if (cur_state == CLASS_STATE_3) {
					if (!name2class.count(symbo)) name2class[symbo].setName(symbo);
					cur_class->addRelation(Relation(&name2class[symbo], inherit));
				}
			}
			Trans(tmp);
		}
		else if (ch == EOF) break;
		else {
			db_err << "unknown symbol" << endl;
			s_in.get(ch);
		}
	}
}

list<Class> CppFileContent::getClasses() {
	list<Class> cls;
	for (auto item : name2class) cls.push_back(item.second);
	db_out << cls.size() << endl;
	for (auto item : cls) {
		db_out << item.getName() << ": " << endl;
		for (auto r : item.getListOfEdges())
			db_out << r.r << ' ' << r.target->getName() << endl;
	}
	return cls;
}