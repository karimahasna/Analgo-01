#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

void createArray(int A[], int size){
    for (int i = 0; i < size; i++){
        A[i] = size - i;
    }
}

// Driver program to test above functions
int main()
{
    int arr[10000];
    int n = sizeof(arr)/sizeof(arr[0]);
    createArray(arr, n);

    cout<<"Descending Element \nSize: " <<n <<endl;

    // Begin
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    bubbleSort(arr, n);

    // End
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout<<endl <<duration <<" microseconds" <<endl;


    return 0;
}