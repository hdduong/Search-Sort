#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int *tmp = (int*)malloc(sizeof(int));

	*tmp = *a;
	*a = *b;
	*b = *tmp;

	free(tmp);
}

// n is inded ; actual size - 1
// extract min first --> Min Heap
void heapify(int arr[], int i, int n) {
	bool leftChildExist = false;
	bool rightChildExist = false;
	
	int minPos = i;

	leftChildExist = (2*i + 1 <= n);
	rightChildExist = (2*i + 2 <= n);

	if (leftChildExist && rightChildExist) {
		minPos = i;
		if (arr[i] > arr[2*i + 1]) {
			if (arr[i] > arr[2*i + 2]) {
				(arr[2*i +1] > arr[2*i + 2]) ? (minPos = 2*i + 2) : (minPos = 2*i +1);
			}
		} else { //arr[i] < arr[2*i + 1]
			(arr[i] > arr[2*i + 2]) ? (minPos = 2*i + 2) : (minPos = i);
		}
	} else if (leftChildExist && !rightChildExist) {
		minPos = i;
		(arr[i] > arr[2*i + 1]) ? (minPos = 2*i + 1) : (minPos = i);

	} else if (!leftChildExist) {
		return;
	}
	if (minPos != i) swap(&arr[i],&arr[minPos]);

	heapify(arr, 2*i + 1, n);
	heapify(arr, 2*i + 2, n);
}

void buildMinHeap(int arr[], int n) {
	// last child 2i + 2 = n -> i = (n/2 - 1)
	for (int i = (n/2-1); i >= 0; i--) {
		heapify(arr,i,n);
	}

}

void HeapSort(int arr[], int n) {
	buildMinHeap(arr,n);
	
	int j = 0;
	int *b = (int*) malloc(n * sizeof(int));
	
	for (int i = n; i >=0; i--) {
		//cout << arr[0] << " ";
		b[j] = arr[0];
		arr[0] = arr[n];

		j++;
		n = n-1;
		buildMinHeap(arr,n);
	}

	for (int i = 0; i < j; i++) {
		//cout << "why not run ";
		arr[i] = b[i];
	}
	
	//for (int i = 0; i < j; i++) {
	//}

	b = NULL; // IMPORTANT
	free(b);
}


void main() {
	//int arr[] = {38,27,43,3,9,82,10};
	// int arr[] = {4,10,3,5,1};
	int arr[] = {4,10,3,5,8};
	int size = sizeof(arr)/sizeof(int);
	int n = size - 1;
	
	//heapify(arr, 0, n);
	//buildMinHeap(arr,n);
	
	HeapSort(arr,n);

	for (int i = 0; i < size ;i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}