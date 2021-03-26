/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 3, Part B
 * Heap Class function definition
 */

#include "heap.h"
#include <string>

//template <class T>
heapify::heapify(vector<string> &item){
    list = item;
};

//template <class T>
int heapify::parent(int n)
{
    return floor(n/2);
}

//template <class T>
int heapify::left(int n)
{
    return 2*n;
}

//template <class T>
int heapify::right(int n)
{
    return (2*n) + 1;
}

//template <class T>
int heapify::getItem(int n)
{
    //return heap<string>.list[n];
    return 0;
}

//template <class T>
void heapify::intitializeMaxHeap(){

}

//template <class T>
void heapify::maxHeapify(vector<string> &arr, int i, int length, int heapsize)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    string temp;

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
        maxHeapify(arr, largest, length, heapsize);
    }
}

//template <class T>
void heapify::buildMaxHeap(vector<string> &arr, int n)
{
    int heapsize = n;
    int i;
    for(i= (n/2); i>=1; i--)
    {
        maxHeapify(arr, i, n, heapsize);
    }
}

//template <class T>
void heapify::heapsort(vector<string> &arr, int length)
{
    int i;
    string temp;
    int heapsize = length;

    buildMaxHeap(arr, length);

    cout << "Constructed heap: ";
    //read words

    for(i = length; i > 1; i--)
    {
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heapsize = heapsize - 1;
        maxHeapify(arr, 1, length, heapsize);
    }
}