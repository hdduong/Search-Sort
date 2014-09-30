#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define RANGE 9
/* 
Given an array of numbers of size n. It is also given that the array elements are 
in range from 0 to n^2 – 1. Sort the given array in linear time.

Look at : 00. Searching and Sorting.docx
*/

void printArray(int arr[], int n) ;

void countingSort(int arr[], int arrIndex[], int n) { //n: index of array--> (size - 1)
	int countArr[RANGE + 1]; // number of elements in range
	int* b = (int*) malloc(sizeof(int) * (n+1));
	
	for (int i = 0; i < RANGE + 1; i++) {
		countArr[i] = -1;
	}

	// printArray(arr,n);

	// first loop: count elements
	for (int i = 0; i <= n;i++) {
		if (countArr[arr[i]] == -1) countArr[arr[i]] = 0;
		countArr[arr[i]]++ ;
	}

	// second loop to update countArr 
	for (int i = 1; i <= RANGE; i++) {
		countArr[i]  = (countArr[i] == -1 ? 0 : countArr[i]) + ( (countArr[i-1]== -1) ? 0 : countArr[i-1] );
	}

	//third loop to place item in place
	for (int i = 0; i <= n; i++) {
		if (countArr[arr[i]] != -1) { // no counting
			b[ countArr[arr[i]] -1 ] = arr[i]; // minus each index 1 since number of elements > index by one
			arrIndex[i] = countArr[arr[i]] -1 ;
			countArr[arr[i]]--;
		}
	}

	for (int i = 0; i <=n; i++) {
		arr[i] = b[i];
	}
}


void printArray(int arr[], int n) {
	for (int i = 0; i <= n; i++) {
		cout << arr[i] << "    ";
	}
	cout << "\n";
}

void main() {
	//int arr[] = {0,23,14,12,9};
	int arr[] = {0,2,1,2,9,8,0,2,4,5,9,6,7,0,1};
	int size = sizeof(arr)/ sizeof(int);
	int n = size - 1;

	int start= 0;
	int end = n;


	int* arrIndex = (int*) malloc(sizeof(int) * size);
	countingSort(arr,arrIndex,n);
	printArray(arr,n);
	printArray(arrIndex,n);
}