#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* a = new int[n];
	int* sortedArray = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sortedArray[i] = a[i];
	}

	sort(sortedArray, sortedArray + n);

	int indexOfFirstConflict = -1;
	int indexOfFirstConflictInUnsorted = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] != sortedArray[i]) {
			if (indexOfFirstConflict != -1) {
				cout << "no" << endl;
				return 0;
			}
			indexOfFirstConflict = i;

			for (int j = indexOfFirstConflict; j < n; j++) {
				if (a[j] == sortedArray[indexOfFirstConflict]) {
					indexOfFirstConflictInUnsorted = j;
				}
			}

			if (indexOfFirstConflictInUnsorted >= n) {
				cout << "no" << endl;
				return 0;
			}

			for (int k = indexOfFirstConflictInUnsorted; k >= indexOfFirstConflict; k--) {
				if (a[k] != sortedArray[i]) {
					cout << "no" << endl;
					return 0;
				}
				i++;
			}
		}
	}
	cout << "yes" << endl;
	if (indexOfFirstConflict == -1) {
		cout << 1 << " " << 1 << endl;
	}
	else { cout << indexOfFirstConflict + 1 << " " << indexOfFirstConflictInUnsorted + 1 << endl; }

	delete[] a;
	delete[] sortedArray;
	return 0;
}