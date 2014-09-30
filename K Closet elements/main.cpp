#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
0(Lgn + k) algorithm
Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45
*/

int getMinPosition(int arr[], int i, int j, int k, int n) {
	if (i < 0) return j;
	if (j > n) return i;

	int iabs = abs(arr[i]- k);
	int jabs = abs(arr[j]- k);

	return (iabs < jabs) ? i : j;
}


// minimum elements that bigger or equal k
int findNearestNeighbor(int arr[], int start, int end, int k, int n) {
	int middle = start + (end - start) / 2;
	if (arr[middle] == k) return middle;

	if (end < start) return -1;

	if ( (end == start)  || (end == start + 1)) {
		return getMinPosition(arr,start, end, k,n);
	}

	if (arr[end] < k) return end;
	if (arr[start] > k) return start;

	int childK = -1;
	if (arr[middle] < k) {
		childK = findNearestNeighbor(arr, middle+ 1, end, k,n);
	}
	else if (arr[middle] > k) {
		childK = findNearestNeighbor(arr, start, middle-1, k,n);
	}

	if (childK != -1) {
		childK = getMinPosition(arr, childK, middle,k,n);
	}

	return (childK == -1) ? middle:childK;

}

void printKNearest(int arr[], int start, int end, int X, int k ,int n) {
	int kPosition = findNearestNeighbor(arr, start, end, X,n);
	int numElemetns = 0; 

	if (kPosition == start) {
		while (numElemetns < k) {
			if (arr[kPosition + numElemetns] != X)
				cout << arr[kPosition + numElemetns] << "  ";
			else {
				k++;
			}
			numElemetns++;
		}
		return;
	}

	if (kPosition == end) {
		while (numElemetns < k) {	
			if (arr[kPosition - numElemetns] != X)
				cout << arr[kPosition - numElemetns] << "  ";
			else {
				k++;
			}
			numElemetns++;
		}
		return;
	}

	
	int goOnLeft = 1;
	int goOnRight = 1;
	int printElement = kPosition;
	while (numElemetns < k) {
		if (arr[printElement] != X) {
			cout << arr[printElement] << "  ";		
		} else k++;
		printElement = getMinPosition(arr,kPosition-goOnLeft,kPosition + goOnRight,X,n);
		if(printElement == kPosition - goOnLeft)
			goOnLeft++;	
		else
			goOnRight++;

		numElemetns++;
	}
	cout << "\n";

}


void main() {
	int arr[] = {12,16,22,30,35,39,42,45,48,50,53,55,56};
	int size = sizeof(arr)/ sizeof(int);
	int n = size - 1;

	int start= 0;
	int end = n;
	//int X = 15;
	//int X = 12;
	//int X = 13;
	//int X = 11;
	//int X = 35;
	int X = 57;


	printKNearest(arr,start,end,X,4,n);


	//cout << kPosition << "\n";


}