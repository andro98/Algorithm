#pragma once
#include<iostream>
#include<vector>
using namespace std;

class KMST
{
private:
	int Nodes;
	int* set;
	int* weight;

	struct Edge {
		int source;
		int dest;
		int w;
	};
	vector<Edge> myList;
	vector<Edge> graph;

	void Gsort();
	void Union(Edge,int,int);
	int findCount(int node);
	int find(int);
	void Init();
public:
	KMST(int);
	void add(int, int,int);
	void runAlgo();
	void print();
	~KMST();
};

