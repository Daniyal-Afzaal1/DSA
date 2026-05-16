#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end){
    int idx = start-1, pivot = arr[end];
    for(int i=start; i<end; i++){
        if(arr[i] <= pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);

    return idx;   //returns the correct pivot index
}

void Quick_Sort(vector<int> &arr, int start, int end){
    if(start >= end){
        return;
    }
    int pivotIdx = partition(arr, start, end);
    Quick_Sort(arr,start,pivotIdx-1); //right
    Quick_Sort(arr,pivotIdx+1,end); //left
}

void printArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr = {12,13,35,8,32,17};
    Quick_Sort(arr,0,arr.size()-1);
    printArray(arr);
}