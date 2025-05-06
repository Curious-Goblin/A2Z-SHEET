#include "bits/stdc++.h"
using namespace std;

struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    int parent(int i);
    int left(int i);
    int right(int i);
    void deleteKey(int i);
    void insertKey(int k);
    void decreaseKey(int i, int new_val);
    void MinHeapify(int i);
};

int MinHeap::extractMin() {
    if(heap_size<=0){
        return -1;
    }
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }
    
    int min = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return min;
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int k) {
    if(heap_size == capacity){
        return;
    }

    heap_size++;
    int i = heap_size-1;
    harr[i] = k;
    decreaseKey(i,k);
}

void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int main(){
    MinHeap h(10);
    return 0;
}