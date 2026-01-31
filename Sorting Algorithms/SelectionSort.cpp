#include <bits/stdc++.h>
using namespace std;

void SeclectionSort(int arr[], int n){
	for(int i=0; i<n-1; i++){ //last element becomes sorted as other become sorted
		int min = i;
		for(int j=i+1; j<n; j++){ // i+1 as starts compare with the next element
			if(arr[j]<arr[min]){
				min = j;
			}
		}
		swap(arr[i],arr[min]);
		
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

	SeclectionSort(arr,n);
	PrintArray(arr,n);

	return 0;
}