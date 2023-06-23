#include <iostream>
#include <stdlib.h>
using namespace std;

#define LENGTH 100

// 템플릿화 하여 제너릭 프로그래밍 구현

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

// 조금 더 빠른 이진 삽입 정렬
template<class T>
void BinaryInsertionSort(T* A)
{
	for (int i = 1; i < LENGTH; i++)
	{
		int key = A[i];

		int h, l;							// high, low
		for (h = i, l = 0; l < h;) {		// Binary Search ,  key와 가장 가까운 큰 값을 찾음(없을 시 Key값)
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

// 1~1000까지의 무작위 정수
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
	int* A = new int[LENGTH];					// 동적 생성
	Random(A);
	int* B = new int[LENGTH];					// 복제
	for (int i = 0; i < LENGTH; i++) {
		B[i] = A[i];				
	}
	cout << "InsertionSort\n";					// 삽입 정렬
	cout << "Original : ";
	Output(A);
	InsertionSort(A);
	cout << "\nResult : ";
	Output(A);

	cout << "\nBinaryInsertionSort\n";			// 이진 삽입 정렬
	cout << "Original : ";
	Output(B);
	BinaryInsertionSort(B);
	cout << "\nResult : ";
	Output(B);


	delete[] A;									// 반환
	delete[] B;									// 반환
	return 0;
}