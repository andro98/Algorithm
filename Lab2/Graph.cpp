#include "Graph.h"



Graph::Graph(int n)
{
	nodes = n;
	graph = new vector<int>[nodes];

}

void Graph::add(int v, int e)
{
	if (v < 0 || v>nodes) {
	}
	else {
		graph[v].push_back(e);
		graph[e].push_back(v);
	}
}

void Graph::print()
{
	//Initialize matrix
	int** matrix = new int*[nodes];
	for (int i = 0; i < nodes; i++)
		matrix[i] = new int[nodes];

	//given values 0
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			 matrix[i][j] = 0;
		}
	}


	for (int i = 0; i < nodes; i++) {
		vector<int> list = graph[i];
		for (int j = 0; j < list.size(); j++) {
			matrix[i][list[j]] = 1;
		}
	}


	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			 cout << matrix[i][j]<<"   ";
		}
		cout << endl;
	}
}


Graph::~Graph()
{
	delete[] graph;
}
