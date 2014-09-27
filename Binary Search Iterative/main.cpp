#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

int binarySearch(int arr[], int x, int size) {
	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) /2;

	while (mid < end) {
		if (arr[mid] == x)
			return mid;

		if (arr[mid] < x) { //on right hand
			start = mid + 1;
			mid = start + (end -start) /2;
		}
		else if (arr[mid] > x) {
			end = mid - 1;
			mid = start + (end - start) /2;
		}
	}

	return -1;
}


void main() {
	int arr[] = {2,4,5,10,40 };
	int n = sizeof(arr)/sizeof(int);
	int x = 10;
	int position = binarySearch(arr,10,n);
	cout << position << "\n";

}