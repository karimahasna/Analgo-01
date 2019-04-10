#include <iostream>
#include <chrono>
#include <math.h>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void createArray(int A[], int size){
    for (int i = 0; i < size; i++){
        A[i] = size - i;
    }
}

/* Driver program to test insertion sort */
int main()
{
    int arr[10000];
    int n = sizeof(arr)/sizeof(arr[0]);
    createArray(arr, n);

    cout<<"Descending Element \nSize: " <<n <<endl;

    // Begin
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    insertionSort(arr, n);

    // End
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<endl <<duration <<" microseconds" <<endl;

    return 0;
}