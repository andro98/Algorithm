#include<iostream>
#include<algorithm>
using namespace std;

int main ()
{
	int T;
	cin >> T;
	for ( int i = 0; i < T; i++ ){
		int N , X;
		int* bottles;
		int c = 0 , num = 0;
		cin >> N >> X;
		bottles = new int[N];
		for ( int j = 0; j < N; j++ ){
			cin >> bottles[j]; 
		}
		sort (bottles , bottles + N);
		for ( int j = 0; j < N; j++ ){
			c += bottles[j];
			if ( c > X ){
				c -= bottles[j];
				break;
			}
			num++;
		}
		cout << num << endl;
		delete[]bottles;
	}

	return 0;
}