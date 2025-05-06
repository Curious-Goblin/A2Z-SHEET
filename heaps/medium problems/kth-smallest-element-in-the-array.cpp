#include "bits/stdc++.h"

using namespace std;

class MaxHeap{
    public:
    int capacity;
    vector<int> heap;
    MaxHeap(int val){
        capacity = val;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int val){
        if(heap.size() < capacity){
            heap.push_back(val);
            heapifyUp(heap.size()-1);
        }
        else{
            if(val < heap[0]){
                heap[0] = val;
                heapifyDown(0);
            }
        }
    }
    void heapifyUp(int i){
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void heapifyDown(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if(left < heap.size() && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < heap.size() && heap[right] > heap[largest]){
            largest = right;
        }
        if(largest != i){
            swap(heap[largest],heap[i]);
            heapifyDown(largest);
        }
    }
    int getRoot(){
        return heap[0];
    }
};

class Solution{
    public:
        // O(NlogK)
        int kthSmallest(vector<int> &arr, int k) {
            MaxHeap h(k);
            for(int i = 0; i < arr.size(); i++){
                h.insert(arr[i]);
            }
            return h.getRoot();
        }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.kthSmallest(nums,k);
    return 0;
}