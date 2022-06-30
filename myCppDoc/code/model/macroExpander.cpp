#include "model/macroExpander.h"
using namespace std;

string MacroExpander::process(fstream &f) {
	/* not implemented now */
	string str;
	char buffer[1024];
	while (!f.eof()) {
		f.getline(buffer, 1024);
		str += string(buffer);
	}
	return str;
}