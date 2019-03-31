#include<iostream>
#include<math.h>
using namespace std;

#define PARENT(i)(floor(i / 2))
#define LEFT(i)(2*i)
#define RIGHT(i)(2*i + 1)

struct Heap{
	int heap_size;
	int* A;
};

void MaxHeapify(Heap&, int);
void BuildMaxHeap(Heap&);
void HeapSort(Heap&);
void PrintHeap(Heap&, int);
void Init(Heap&, int&);
void GetHeap(Heap&);

int main()
{
	int n; 
	Heap A;
	Init(A, n);
	GetHeap(A);
	HeapSort(A);
	PrintHeap(A,n);
}

void Init(Heap& A, int& n)
{
	cout << "Enter size: ";
	cin >> n;
	A.heap_size = n;
	A.A = new int[n];
}

void GetHeap(Heap& A)
{
	cout << "Enter Heap: ";
	for (int i = 0; i < A.heap_size; i++)
		cin >> A.A[i];
}

void PrintHeap(Heap& A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A.A[i] << " ";
	cout << endl;
}

void HeapSort(Heap& A)
{
	BuildMaxHeap(A);
	for (int i = A.heap_size - 1; i >= 1; i--)
	{
		swap(A.A[0], A.A[i]);
		A.heap_size--;
		MaxHeapify(A, 0);
	}
}

void BuildMaxHeap(Heap& A)
{
	for (int i = floor(A.heap_size / 2); i >= 0; i--)
	{
		MaxHeapify(A, i);
	}
}

void MaxHeapify(Heap& A , int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	
	if (l < A.heap_size && A.A[l] > A.A[i]) largest = l;
	else largest = i;

	if (r < A.heap_size && A.A[r] > A.A[largest]) largest = r;

	if (largest != i)
	{
		swap(A.A[i], A.A[largest]);
		MaxHeapify(A, largest);
	}
}