#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class heapify
{
public:
    vector<string> list;

    int parent(int n);
    int left(int n);
    int right(int n);
    int getItem(int n);

    heapify(vector<string> &arr);

    void intitializeMaxHeap();
    void maxHeapify(vector<string> &arr, int i, int length, int heapsize);
    void buildMaxHeap(vector<string> &arr, int n);

    void heapsort(vector<string> &arr, int length);
private:
};

#endif
