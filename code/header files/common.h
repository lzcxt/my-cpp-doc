#pragma once
#include<list>
#include<vector>
#include<iostream>
using namespace std;

enum Relation_enum{
	inherit, include
};

class Class;

struct Relation {
	Class* target;
	Relation_enum r;
};

struct Class {
	string name;
	vector<string> attributes;
	list<Relation> list_edges;
};

struct Block {
	int width, height;
	Class this_class;

	Block(const int& w, const int& h, const Class& c);
	bool operator<(const Block& np) const;
};