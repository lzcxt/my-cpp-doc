#pragma once
#include<list>
#include<vector>
#include<iostream>
using namespace std;

enum Relation_enum{
	inherit, conclude
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
};