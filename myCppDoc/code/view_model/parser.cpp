#include "common.h"
#include "parser.h"
#include "macroExpander.h"
#include "cppFileContent.h"
#include <fstream>
using namespace std;

const list<shared_ptr<Class>>& Parser::parse(list<string> file_names) {
	//SendMsg("Parse::parse start");
	vector<string> bad_file_names;
	MacroExpander me;
	CppFileContent cfc;
	for (auto name : file_names) {
		//SendMsg(name);
		fstream f(name, fstream::in);
		if (!f.is_open()) { bad_file_names.push_back(name); continue; }
		cfc.pushBack(me.process(f));
	}
	if (bad_file_names.size()) {
		string info;
		for (auto name : bad_file_names) info += name + " ";
		throw m_Exception("Could not open { " + info + "}");
	}
	return cfc.getClasses();
}