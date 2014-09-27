#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

void merge(int arr[], int start, int middle, int end);

void mergeSort(int arr[], int start, int end) {
	if (end > start) {
		int middle = start + (end - start) / 2;
	
		mergeSort(arr, start, middle);
		mergeSort(arr,middle+1,end);
		merge(arr,start,middle,end);

	}
	else if (end == start) {
		
	}

}

// arr[] passed by reference. Similar to *

void merge(int arr[], int start, int middle, int end) {
	// merge from start -> middle, middle+1 -> end
	
	int* b = (int*) malloc(sizeof(int) * (end - start + 1));

	int firstHalf = start;
	int secondeHalf = (middle + 1);
	int overall = 0;

	while( (firstHalf <= middle) && (secondeHalf <= end) ) {
		if (arr[firstHalf] < arr[secondeHalf]) {
			b[overall] = arr[firstHalf];
			firstHalf++;
		}
		else {
			b[overall] = arr[secondeHalf];
			secondeHalf++;
		
		}
		overall++;
	}

	while (firstHalf <= middle) {
		b[overall] = arr[firstHalf];
		firstHalf++;
		overall++;
	}

	while (secondeHalf <= end) {
		b[overall] = arr[secondeHalf];
		secondeHalf++;
		overall++;
	}

	for (int i = start, j = 0; i <= end; i++, j++) {
		arr[i] = b[j];
	}
	
}


void main() {
	//int arr[] = {38,27,43,3,9,82,10};
	int arr[] = {12,11,13,5,6,7};
	int n = sizeof(arr)/sizeof(int);
	int x = 10;
	
	// merge(arr,0,3,n-1);

	mergeSort(arr, 0, n-1);

	for (int i = 0; i < n ;i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}