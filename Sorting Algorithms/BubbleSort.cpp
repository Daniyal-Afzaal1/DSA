#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[],int n){
	for(int i=0; i<n-1; i++){
		bool isSwapped =false; //flag to check whether array is sorted initially
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				isSwapped =true;
			}
		}
		if(!isSwapped){return;} //after one iteration if no swapping then returns
	}
}

void printArray(int arr[],int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {4,1,5,2,3};
	int  n = sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr,n);
	printArray(arr,n);
	
	return 0;
}
