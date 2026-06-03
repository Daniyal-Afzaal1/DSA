#include <iostream>
using namespace std;

//All algos of Heap are written on assumption that we are starting from 1 index

void Insertion(int Heap[],int &size,int value){
    size++;
    int i = size;
    Heap[i] = value;
    while(i>1 && Heap[i]>Heap[i/2]){
        swap(Heap[i],Heap[i/2]);
        i=i/2;
    }
}

void maxHeapify(int Heap[], int size, int i){ //to correct one node which is in invalid position
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=size && Heap[left]>Heap[largest]){
        largest = left;
    }
    if(right<=size && Heap[right]>Heap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(Heap[i], Heap[largest]);
        maxHeapify(Heap,size,largest);
    }
}

void build_Max_Heap(int Heap[], int size){
    for(int i=size/2; i>=1; i--){
        maxHeapify(Heap,size,i);
    }
}

int extractMax(int Heap[],int &size){
    int maxValue = Heap[1];
     Heap[1] = Heap[size];
     size--;
     maxHeapify(Heap,size,1);

     return maxValue;
}

void HeapSort(int arr[],int size){
    build_Max_Heap(arr,size);
    for(int i=size; i>=2; i--){      //>=2 b/c first element is always sorted
        swap(arr[i],arr[1]);
        size--;                      //b/c we sorted the last
        maxHeapify(arr,size,1);
    }
}

//testing main for all fn except Build_Max_Heap
// int main() 
// {
//     int Heap[20] = {0}; // index 0 unused
//     int size = 0;

//     // Insert values
//     Insertion(Heap, size, 4);
//     Insertion(Heap, size, 1);
//     Insertion(Heap, size, 3);
//     Insertion(Heap, size, 2);
//     Insertion(Heap, size, 16);
//     Insertion(Heap, size, 9);
//     Insertion(Heap, size, 10);
//     Insertion(Heap, size, 14);
//     Insertion(Heap, size, 8);
//     Insertion(Heap, size, 7);

//     cout << "Heap after insertions:\n";

//     for(int i = 1; i <= size; i++)
//     {
//         cout << Heap[i] << " ";
//     }
//     cout << endl;

//     cout << "\nExtracted Max = "
//          << extractMax(Heap, size) << endl;

//     cout << "\nHeap after extractMax:\n";

//     for(int i = 1; i <= size; i++)
//     {
//         cout << Heap[i] << " ";
//     }
//     cout << endl;

//     HeapSort(Heap, size);

//     cout << "\nAfter Heap Sort:\n";

//     for(int i = 1; i <= size; i++)
//     {
//         cout << Heap[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

int main()  //main for Build_Max_Heap testing
{
    int Heap[11] = {0,4,1,3,2,16,9,10,14,8,7};
    int size = 10;

    cout << "Before Build Max Heap:\n";

    for(int i=1; i<=size; i++)
    {
        cout << Heap[i] << " ";
    }

    cout << endl;

    build_Max_Heap(Heap,size);

    cout << "\nAfter Build Max Heap:\n";

    for(int i=1; i<=size; i++)
    {
        cout << Heap[i] << " ";
    }

    cout << endl;
}