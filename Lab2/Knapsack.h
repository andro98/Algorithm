#pragma once
#include<iostream>
using namespace std;

class Knapsack
{
private:
	struct Knap{
		int* value;
		int* weigth;
	};
	int _Capacity;
	int _Size;
	Knap _knap;

	void getKanp();
public:
	Knapsack(int,int);
	int runAlgo(int, int);
	~Knapsack();
};

