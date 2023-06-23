#include <iostream>
#include <stdlib.h>
using namespace std;

#define LENGTH 100

// ���ø�ȭ �Ͽ� ���ʸ� ���α׷��� ����

template<class T>
void InsertionSort(T* A)
{
	for (int j = 1; j < LENGTH; j++)
	{
		int key = A[j];
		//Insert A[j] into the sorted sequence A[0..j-1]
		int i = j - 1;
		while ((i >= 0) && (A[i] > key))
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

// ���� �� ���� ���� ���� ����
template<class T>
void BinaryInsertionSort(T* A)
{
	for (int i = 1; i < LENGTH; i++)
	{
		int key = A[i];

		int h, l;							// high, low
		for (h = i, l = 0; l < h;) {		// Binary Search ,  key�� ���� ����� ū ���� ã��(���� �� Key��)
			int m = (l + h) / 2;
			if (A[m] > key)
				h = m;
			else
				l = m + 1;
		}
		for (int j = i - 1; j >= l;j--)
			A[j + 1] = A[j];
		A[l] = key;
	}
}

// 1~1000������ ������ ����
template<class T>
void Random(T* A) {
	srand(time(0));
	for (int i = 0; i < LENGTH; i++) {
		A[i] = rand() % 1000 + 1;				// Between 1 and 1000
	}
}

template<class T>
void Output(T* A)
{
	for (int i = 0; i < LENGTH; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int main()
{
	int* A = new int[LENGTH];					// ���� ����
	Random(A);
	int* B = new int[LENGTH];					// ����
	for (int i = 0; i < LENGTH; i++) {
		B[i] = A[i];				
	}
	cout << "InsertionSort\n";					// ���� ����
	cout << "Original : ";
	Output(A);
	InsertionSort(A);
	cout << "\nResult : ";
	Output(A);

	cout << "\nBinaryInsertionSort\n";			// ���� ���� ����
	cout << "Original : ";
	Output(B);
	BinaryInsertionSort(B);
	cout << "\nResult : ";
	Output(B);


	delete[] A;									// ��ȯ
	delete[] B;									// ��ȯ
	return 0;
}