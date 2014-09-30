#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define RANGE 9 //maximum in range in couting sort

// Temporary storage need to be filled full in range


void printArray(int arr[], int n);

void countingSort(int arr[], int n) { //n: index of array--> (size - 1)
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
	int arr[] = {1,4,1,2,7,5,2};
	//int arr[] = {1,4,1,2,7,5,2,0};
	int size = sizeof(arr)/ sizeof(int);
	int n = size - 1;
	
	countingSort(arr, n);
	printArray(arr,n);
}



