#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int start,int end, int value, int arr[7]){
     while(start<=end){
        int mid = (start+end)/2;
        if(value>arr[mid]){
            start = mid+1;
        }else if(value<arr[mid]){
            end = mid-1;
        }else if (value == arr[mid]){
            return mid;
        }
     }
     return -1;
}

int main(){
    int arr[7] = {-1,0,3,4,5,9,12};
    cout<<BinarySearch(0,6,12,arr)<<endl;
    }
