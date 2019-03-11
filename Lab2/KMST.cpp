#include "KMST.h"



KMST::KMST(int n)
{
	Nodes = n;
	Init();
}

void KMST::Init() {
	set = new int[Nodes];
	for (int i = 0; i < Nodes; i++)
		set[i] = i;

	weight = new int[Nodes];
	for (int i = 0; i < Nodes; i++)
		weight[i] = 0;
}


void KMST::add(int s, int d, int w)
{
	Edge e;
	e.source = s;
	e.dest = d;
	e.w = w;
	graph.push_back(e);
}

void KMST::runAlgo()
{
	Gsort();
	for (int i = 0; i < graph.size(); i++) {
		Edge e = graph[i];
		int p1 = find(e.source);
		int p2 = find(e.dest);
		if (p1 != p2) {
			Union(e, p1, p2);
			myList.push_back(e);
		}
	}
}

void KMST::Gsort()
{
	for (int i = 0; i < graph.size() - 1; i++) {
		for (int j = i + 1; j < graph.size(); j++) {
			if (graph[j].w < graph[i].w) {
				swap(graph[j], graph[i]);
			}
		}
	}
}

void KMST::Union(Edge e, int p1, int p2)
{
	int c1 = weight[p1];
	int c2 = weight[p2];
	if (c1 > c2) {
		set[e.dest] = p1;
		weight[p1]++;
	}
	else {
		set[e.source] = p2;
		weight[p2]++;
	}
}

int KMST::findCount(int node) {
	int parent = set[node];
	int count = 0;
	while (parent != set[parent]) {
		parent = set[parent];
		count++;
	}
	return count;
}

int KMST::find(int node)
{
	int parent = set[node];
	while (parent != set[parent]) {
		parent = set[parent];
	}
	return parent;
}

void KMST::print() 
{
	for (int i = 0; i < myList.size(); i++) {
		cout << myList[i].source << " " << myList[i].dest << " " << myList[i].w << endl;
	}
}

KMST::~KMST()
{
	delete[]set;
	delete[]weight;
}
