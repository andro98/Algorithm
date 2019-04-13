#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int isCoin (int n , int x1 , int x2){
	return ( double(n /x1) == (double)x2 );
}

int main ()
{
	/*int t;
	cin >> t; */
	/*while ( t > 0 )
	{ */
		int n,m;
		cin >> n;
		int* A1 = new int[n];
		int* A2 = new int[n];

		for ( int i = 0; i < n; i++ ){
			cin >> A1[i];
			A2[i] = A1[i];
		}

		cin >> m;
		int count = 0;
		int** table = new int* [n];
		for ( int i = 0; i < n; i++ )table[i] = new int[n];
		

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < i+1; j++ ){
					table[i][j] = isCoin (m , A1[i] , A2[j]);
				
			}
		}	 
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < i + 1; j++ ){
				count += table[i][j];
			}
		}	   

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ){
				cout << table[i][j] << " ";
			}
			cout << endl;
		}

		cout << count << endl;

		//t--;
	//}
	return 0;
}

/*for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < i + 1; j++ ){
				table[i][j] = i;
				table[j][i] = i;
			}
		}

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ){
				cout << table[i][j] << " ";
			}
			cout << endl;
			}*/