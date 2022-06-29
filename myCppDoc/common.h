#pragma once
#include<list>
#include<vector>
#include<iostream>
using namespace std;

enum Relation{
	inherit, conclude
};

class Node;

class Edge {
	Node* another_class;
	Relation r;
};

class Node {
	string this_class;
	vector<string> attributes;
	list<Edge> list_edges;
};

class Block {
	int width, height;
	Node this_class;
};