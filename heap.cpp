#include "heap.h"

int parent(int n)
{
    return floor(n/2);
}

int left(int n)
{
    return 2*n;
}

int right(int n)
{
    return (2*n) + 1;
}

int getItem(int n)
{
    //return heap<string>.list[n];
    return 0;
}

void intitializeMaxHeap();
void MAXHEAPIFY(int arr[], int i, int length, int heapsize)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    int temp;

    if (l<=heapsize && arr[l] > arr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r<=heapsize && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        MAXHEAPIFY(arr, largest, length, heapsize);
    }
}
void BuildMaxHeap(int arr[], int n)
{
    int heapsize = n;
    int i;
    for(i= (n/2); i>=1; i--)
    {
        MAXHEAPIFY(arr, i, n, heapsize);
    }
}

void heapsort(int arr[], int length)
{
    int i, temp;
    int heapsize = length;

    BuildMaxHeap(arr, length);

    cout << "Constructed heap: ";
    //read words

    for(i = length; i > 1; i--)
    {
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heapsize = heapsize - 1;
        MAXHEAPIFY(arr, 1, length, heapsize);
    }

}