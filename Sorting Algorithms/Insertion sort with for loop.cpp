#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        int indx;
        bool shift = false;
        for(prev; prev>=0; prev--){
            if(curr<arr[prev]){
                arr[prev+1]=arr[prev];
                shift = true;
                indx = prev;
            }
            
        }
        if(shift){
        arr[indx] = curr;
    }
    }
    }

void PrintArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[] = {4,1,5,2,3};
    InsertionSort(arr,5);
    PrintArray(arr,5);

}
