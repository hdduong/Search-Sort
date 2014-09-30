#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void printArray(int arr[], int n);

bool isSwap(int arr[], int prev, int next) {
	return (arr[prev] > arr[next]) ? true:false;
}

int almostBinarySearch(int arr[], int start, int end, int X) {
	if (end > start) {
		int middle = start + (end - start) /2;

		if (arr[middle] == X) return middle;
		if ( (middle + 1 <= end) && (arr[middle+1] ==  X) ) return (middle+1);
		if ( (middle - 1 >= start) && (arr[middle- 1] == X)) return (middle -1);

		if ( (arr[middle] < X) && ((middle - 1 > start) && (arr[middle-1] <  X))  && 
			((middle + 1 < end) && (arr[middle+1] < X)) 
			) {
				
				return almostBinarySearch(arr,middle+1,end,X);
		} else if  ( (arr[middle] > X ) && ((middle - 1 > start) && (arr[middle-1] >  X))  && 
			((middle + 1 < end) && (arr[middle+1] > X)) 
			) {
				return almostBinarySearch(arr,start,middle-1,X);
		}
	}

	return -1;


}

void printArray(int arr[], int n) {
	for (int i = 0; i <= n; i++) {
		cout << arr[i] << "    ";
	}
	cout << "\n";
}


void main() {
	int arr[] = {10,3,40,20,50,80,70};
	//int arr[] = {1,4,1,2,7,5,2,0};
	int size = sizeof(arr)/ sizeof(int);
	int n = size - 1;
	
	int start = 0;
	int end = n;
	int X = 20;

	int position =  almostBinarySearch(arr,start,end,X);
	cout << position << "\n";
}


