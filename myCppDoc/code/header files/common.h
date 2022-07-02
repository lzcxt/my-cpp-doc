#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <exception>
using namespace std;

enum Relation_enum{
	inherit, include
};

class Class {
	string name;
	vector<string> attributes;
	vector<string> superclasses;
	vector<string> components;

public:
	Class(string name = "Not_Defined") : name(name) {}
	void setName(string name_) {
		name = name_;
	}
	void addAttributes(string attr) {
		attributes.push_back(attr);
	}
	void addSuperclasses(string sup) {
		superclasses.push_back(sup);
	}
	void addComponents(string com) {
		components.push_back(com);
	}
	const string& getName() const {
		return name;
	}
	const vector<string>& getSuperclasses() const {
		return superclasses;
	}
	const vector<string>& getComponents() const {
		return components;
	}
	const vector<string>& getAttributes() const {
		return attributes;
	}
};

class Block {
	int width, height;
	Class this_class;

public:
	Block(const int& w, const int& h, const Class& c);
	bool operator<(const Block& np) const;
	int getWidth() const;
	int getHeight() const;
	Class getThisClass() const;
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