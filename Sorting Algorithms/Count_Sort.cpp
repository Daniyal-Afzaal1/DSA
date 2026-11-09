#include <iostream>
using namespace std;

void CountSort(int arr[], int n){
    int max = arr[0];

    //finding max value
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int count[7] = {0}; //max+1

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    //adding current count into previous one
    for(int i=1; i<=max; i++){
        count[i] += count[i-1];
    }

    int sortedArray[n];

    for(int i=n-1; i>=0; i--){
        sortedArray[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = sortedArray[i];
    }

}

int main(){
    int arr[] = {1,3,2,3,4,1,6,4,3};

    CountSort(arr,9);
    
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}