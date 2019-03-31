#include<iostream>
#include"Knapsack.h"
using namespace std;

int main()
{
	int n, c;
	cout << "Enter size: "; cin >> n;
	cout << "Enter capacity: "; cin >> c;
	Knapsack knap(n, c);
	cout << "Max: " << knap.runAlgo(n - 1, c) << endl;
	return 0;
}
	/*cout << "Lab 2" << endl;
	int node;
	cin >> node;
	KMST g(node);
	int x, y,w;
	while(true)
	{
		cin >> x >> y >> w;
		if (x != -1 && y != -1 && w!=-1) {
			g.add(x, y,w);
		}
		else {
			break;
		}
	} 
	g.runAlgo();
	g.print();*/