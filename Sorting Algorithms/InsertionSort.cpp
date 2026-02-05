#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int curr = arr[i];
		int prev = i-1;
		while(prev>=0 && arr[prev]>curr){
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1] = curr;
	}
}

void PrintArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {77,33,44,11,88,22,66,55};
	int n = sizeof(arr)/sizeof(arr[0]);

	InsertionSort(arr,n);
	PrintArray(arr,n);

	return 0;
}