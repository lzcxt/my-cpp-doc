#include "common.h"
#include "model/parser.h"
#include "model/macroExpander.h"
#include "model/cppFileContent.h"
#include "model/classRelationGenerator.h"
#include <fstream>
using namespace std;

list<Class> Parser::parse(list<string> file_names) {
	vector<string> bad_file_names;
	MacroExpander me;
	CppFileContent cfc;
	for (auto name : file_names) {
		fstream f(name, fstream::in);
		if (!f.is_open()) { bad_file_names.push_back(name); continue; }
		cfc.pushBack(me.process(f));
	}
	if (bad_file_names.size()) {
		string info;
		for (auto name : bad_file_names) info += name + " ";
		throw m_Exception("Could not open { " + info + "}");
	}
	/*
	ClassRelationGenerator crg;
	TOKEN cur = cfc.getToken();
	while (cur != EOF_) {
		crg.pushBack(cur);
		cur = cfc.getToken();
	}
	*/
	return cfc.getClasses();
}