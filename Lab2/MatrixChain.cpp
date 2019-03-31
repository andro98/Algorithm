#include "MatrixChain.h"
#include<iostream>
using namespace std;


void MatrixChain::getD()
{
	d = new int[n];
	for (int i = 0; i < n + 1; i++) {
		cin >> d[i];
	}
}

int MatrixChain::runAlgo(int i, int j) {
	//base case nfs el matrix ex: A

	int min = INT_MAX;
	
	if (i == j) {
		return 0;
	}
	
	if (Table[i][j] != 0) {
		return Table[i][j];
	}

	for (int k = i; k < j; k++) {
		Table[i][j] = runAlgo(i, k) + runAlgo(k + 1, j) + (d[i - 1] * d[k] * d[j]);
		if (Table[i][j] < min)
			min = Table[i][j];
	}
	return min;
}

MatrixChain::MatrixChain(int x)
{
	n = x;
	getD();
	table = new int*[n];
	for (int i = 0; i < n; i++)
		table[i] = new int[n];
	Table = new int*[n];
	for (int i = 0; i < n; i++)
		Table[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j< n; j++){
			Table[i][j] = 0;
		}
	}

}


MatrixChain::~MatrixChain()
{
	/*delete[]d;
	delete[]table;*/
}
