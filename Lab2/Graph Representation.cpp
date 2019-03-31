// Given an undirected graph in adjacency list way
// Display it in adjacency matrix
#include<iostream>
#include<vector>
using namespace std;

int nodes; // number of nodes
vector<int>* graph;
int** matrix;

void Initialize ();		  
void Add (int , int);
void InitMatrix();
void Convert ();
void PrintMatrix();


int main ()
{
	cin >> nodes;
	Initialize ();
	int v , e;
	do{
		cin >> v >> e;
		Add (v , e);
	} while ( v != -1 && e != -1 );
	InitMatrix ();
	Convert ();
	PrintMatrix ();
	return 0;
}			  

void Initialize (){
	graph = new vector<int>[nodes];
}

void Add (int v , int e){
	if ( v < 0 || v>nodes ) {
		return;
	}
	else {
		graph[v].push_back (e);
		graph[e].push_back (v);
	}
}

void InitMatrix (){
	//Initialize matrix
	 matrix = new int*[nodes];
	for ( int i = 0; i < nodes; i++ )
		matrix[i] = new int[nodes];

	//given values 0
	for ( int i = 0; i < nodes; i++ ) {
		for ( int j = 0; j < nodes; j++ ) {
			matrix[i][j] = 0;
		}
	}
}

void Convert (){
	for ( int i = 0; i < nodes; i++ ) {
		vector<int> list = graph[i];
		for ( int j = 0; j < list.size (); j++ ) {
			matrix[i][list[j]] = 1;
		}
	}
}

void PrintMatrix (){
	for ( int i = 0; i < nodes; i++ ) {
		for ( int j = 0; j < nodes; j++ ) {
			cout << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}
