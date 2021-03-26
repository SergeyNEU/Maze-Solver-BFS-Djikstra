#include <iostream>
#include <vector>
#include <cmath>

#ifndef HEAP_H
#define HEAP_H

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
    void maxHeapify(vector<T> &arr, int i, int length, int heapsize);
    void buildMaxHeap(vector<T> &arr, int n);

    void heapsort(vector<T> &arr, int length);
private:
};

#endif
