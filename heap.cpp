#include "heap.h"

template <class T>
int heap<T>::parent(int n)
{
    return floor(n/2);
}

template <class T>
int heap<T>::left(int n)
{
    return 2*n;
}

template <class T>
int heap<T>::right(int n)
{
    return (2*n) + 1;
}

template <class T>
int heap<T>::getItem(int n)
{
    //return heap<string>.list[n];
    return 0;
}

template <class T>
void heap<T>::intitializeMaxHeap(){

}

template <class T>
void heap<T>::maxHeapify(vector<T> &arr, int i, int length, int heapsize)
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

template <class T>
void heap<T>::buildMaxHeap(vector<T> &arr, int n)
{
    int heapsize = n;
    int i;
    for(i= (n/2); i>=1; i--)
    {
        maxHeapify(arr, i, n, heapsize);
    }
}

template <class T>
void heap<T>::heapsort(vector<T> &arr, int length)
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