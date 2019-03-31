#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Graph
{
private:
	int nodes;
	vector<int>* graph;
public:
	Graph(int );
	void add(int, int);
	void print();
	~Graph();
};

