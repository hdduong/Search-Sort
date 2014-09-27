#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// n is index = size -1
int paritition(int arr[], int start, int end, int n) {
	//if (start > end) return -1;

	int i = start -1;
	int j = start;

	// pivot is last element 
	int pivot = arr[end];

	for (j= start; j < end;j++) { //maximum of j is (end -1)
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[end], arr[i]);
	return i;
}


void quickSort(int arr[], int start, int end, int n) {
	if (start < end) {
		int pivotPos = paritition(arr, start, end,n);
		quickSort(arr,start,pivotPos-1,n);
		quickSort(arr,pivotPos + 1,pivotPos,n);
	}

}

void main() {

	int arr[] = {4,10,3,5,8};
	//int arr[] = {4,10,3,9,5,8};
	int size = sizeof(arr)/sizeof(int);
	int n = size - 1;

	//int pivotPos = paritition(arr,0,n,n);
	quickSort(arr,0,n,n);

	for (int i = 0; i < size ;i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	//cout << pivotPos << "\n";
}