#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> &arr, int start, int mid, int end){
    vector<int> temp;
    int i = start, j = mid+1;

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){ // for remaining left elements
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){ // for remaining right elements
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+start] = temp[idx];
    }

    
}

void Merge_Sort(vector<int> &arr,int start, int end){
    if(start<end){
        int mid = start + (end-start)/2;

        Merge_Sort(arr,start,mid); //left half
        Merge_Sort(arr,mid+1,end); //right half
        merge(arr,start,mid,end);
    }
}

void print_Array(vector<int> arr){
    for(int i : arr){
        cout<< i << " ";
    }
}

int main(){
    vector<int> arr = {12,13,35,8,32,17};
    Merge_Sort(arr,0,arr.size()-1);
    print_Array(arr);

    return 0;
}