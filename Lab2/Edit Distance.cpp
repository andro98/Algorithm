#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str1 , str2;
int** table;

int Minn (int x , int y , int z)
{
	return min (min (x , y) , z);
}

void Init ()
{
	//Initialization
	table = new int*[str1.length () + 1];
	for ( int i = 0; i < str1.length () + 1; i++ )
		table[i] = new int[str2.length () + 1];

	for ( int i = 0; i < str1.length () + 1; i++ )table[i][0] = i;
	for ( int i = 0; i < str2.length () + 1; i++ )table[0][i] = i;
}

void EditDistance ()
{
	for ( int i = 1; i < str1.length () + 1; i++ )
	{
		for ( int j = 1; j < str2.length () + 1; j++ )
		{
			if ( str1[i - 1] == str2[j - 1] )
			{
				table[i][j] = table[i - 1][j - 1];
			}
			else
			{
				table[i][j] = Minn (table[i - 1][j - 1] , table[i][j - 1] , table[i - 1][j]) + 1;
			}
		}
	}
}

void PrintEditDistance ()
{
	for ( int i = 1; i < str1.length () + 1; i++ )
	{
		for ( int j = 1; j < str2.length () + 1; j++ )
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	cout << table[str1.length ()][str2.length ()] << endl;
}

void FreeMemory ()
{ 
	//Free up memory
	for ( int i = 0; i < str1.length () + 1; i++ )delete[] table[i];
	delete[]table;
}

int main ()
{
		cin >> str1 >> str2;
		Init ();
		EditDistance ();
		PrintEditDistance ();
		FreeMemory ();
	return 0;
}