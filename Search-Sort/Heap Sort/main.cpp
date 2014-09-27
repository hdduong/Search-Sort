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
	bool firstChildExist = false;
	bool secondChildExist = false;
	
	int minPos = i;

	firstChildExist = (2*i + 1 <= n);
	secondChildExist = (2*i + 2 <= n);

	if (firstChildExist && secondChildExist) {
		minPos = i;
		if (arr[i] > arr[2*i + 1]) {
			if (arr[i] > arr[2*i + 2]) {
				(arr[2*i +1] > arr[2*i + 2]) ? (minPos = 2*i + 2) : (minPos = 2*i +1);
			}
		} else { //arr[i] < arr[2*i + 1]
			(arr[i] > arr[2*i + 2]) ? (minPos = 2*i + 2) : (minPos = i);
		}
	} else if (firstChildExist && !secondChildExist) {
		minPos = i;
		(arr[i] > arr[2*i + 1]) ? (minPos = 2*i + 1) : (minPos = i);

	} else if (!firstChildExist) {
		return;
	}
	if (minPos != i) swap(&arr[i],&arr[minPos]);

	heapify(arr, 2*i + 1, n);
	heapify(arr, 2*i + 2, n);
}



void main() {
	//int arr[] = {38,27,43,3,9,82,10};
	int arr[] = {4,10,3,5,1};
	int size = sizeof(arr)/sizeof(int);
	int n = size - 1;
	
	heapify(arr, 0, n);
	
	for (int i = 0; i < size ;i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}