#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <exception>
using namespace std;

enum Relation_enum{
	inherit, include
};

class Class;

class Relation {
	Class* target;
	Relation_enum r;
};

class Class {
	string name;
	vector<string> attributes;
	list<Relation> list_edges;
};

class Block {
	int width, height;
	Class this_class;

	Block(const int& w, const int& h, const Class& c);
	bool operator<(const Block& np) const;
};


/**
 * @brief this exception must be catched, and then use 'e.Information()' 
 * to get the information.
 */
class m_Exception : public std::exception {
public:
	m_Exception() {};
	m_Exception(string info_) : info(info_) {}
	virtual const char* what() { return " [ exception ] "; }
	string Information() { return info; }
private:
	string info;
};