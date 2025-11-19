// NewHeap.h
#pragma once

#include <iostream>
#include "jobStack.h"

using namespace std;

class NewHeap {
// private: ?
    Job* heapArray;
    int capacity;
    int heapSize;

public:
    NewHeap(int capacity);

    void MinHeapify(int);

    // returns index of parent of node at index i
    int ParentNode(int i) { return (i - 1) / 2; }

    // returns index of left child of node at index i
    int LeftNode(int i) { return (2 * i + 1); }

    // returns index of right child of node at index i
    int RightNode(int i) { return (2 * i + 2); }

    // extracts the minimum element of heap
    Job PullMinElement();

    // returns the minimum heap
    Job GetMinHeap() { return heapArray[0]; }

    void InsertKey(Job k);

    bool IsHeapEmpty();

    void SwapHeap(Job* heapOne, Job* heapTwo);

    void PrintHeap();

    int SizeOfHeap() { return heapSize; }

    void AddHeapWaitTime();

    int GetRemainingWaitTime();
};