#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class T>

class heap
{
public:
    vector<T> list;

    int parent(int n);
    int left(int n);
    int right(int n);
    int getItem(int n);

    void intitializeMaxHeap();
    void MAXHEAPIFY(int arr[], int i, int length, int heapsize);
    void BuildMaxHeap(int arr[], int n);

    void heapsort(int arr[], int length);
private:
};

#endif
