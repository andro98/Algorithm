
#pragma once
class MatrixChain
{
private:
	int n;
	/*struct dimensions {
		int r, c;
	};/*/
	//dimensions* d;
	int* d;
	int** table;
	void getD();
	int **Table;
	//int k = 1;
public:
	MatrixChain(int);
	int runAlgo(int,int);
	~MatrixChain();
};

