
#include<iostream>
#include<algorithm>
using namespace std;

char find (char* A , char* B , int n)
{
	if ( A[n] == 'A' ) return 'A';
	else if ( B[n] == 'B' ) return 'B';
	else return 'C';
}

int main ()
{
	int T , N , iA , iB;
	char *A , *B;
	cin >> T;
	int* Cases = new int[T];
	for ( int i = 0; i < T; i++ )
	{
		cin >> N;
		int countA = 0 , countB = 0;
		A = new char[20000];
		B = new char[20000];
		for ( int j = 0; j < N; j++ )
		{
			cin >> iA >> iB;
			if ( find (A , B , iA) == 'C' ){
				if ( find (A , B , iB) == 'A' ){
					B[iA] = 'B'; countB++;
				}
				else{
					A[iA] = 'A'; countA++;
				}
			
			}
			if ( find (A , B , iB == 'C')){
				if ( find (A , B , iA) == 'B' ){
					A[iB] = 'A'; countA++;
				}
				else{
					B[iB] = 'B'; countB++;
				}
			}
		}
		Cases[i] = max (countA , countB);
		delete[]A;
		delete[]B;
	}
	for ( int i = 0; i < T; i++ ){
		cout << "Case " << i + 1 << ": " << Cases[i]<< endl;
	}
	delete[]Cases;
	return 0;
}

