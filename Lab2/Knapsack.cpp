#include "Knapsack.h"
#include<algorithm>


void Knapsack::getKanp()
{
	for (int i = 0; i < _Size; i++) {
		cin >> _knap.value[i] >> _knap.weigth[i];
	}
}

int Knapsack::runAlgo(int size, int capacity)
{
	if (capacity < 0) {
		return INT_MIN;
	}
	if (size < 0 || capacity == 0) {
		return 0;
	}
	//case included
	int L = _knap.value[size] + runAlgo(size - 1, capacity - _knap.weigth[size]);
	//case execluded
	int R = runAlgo(size - 1, capacity);
		
	return max(L,R);
}

Knapsack::Knapsack(int s, int c)
{
	_Size = s;
	_Capacity = c;
	_knap.value = new int[s];
	_knap.weigth = new int[s];
	getKanp();
}



Knapsack::~Knapsack()
{
	delete[] _knap.value;
	delete[] _knap.weigth;
}
