#include "bits/stdc++.h"

using namespace std;

class MinHeap{
    public:
    int capacity;
    vector<int> heap;
    MinHeap(int val){
        capacity = val;
    }
    int parent(int i){
        return (i - 1)/2;
    }
    void insert(int val){
        if(heap.size()<capacity){
            heap.push_back(val);
            heapifyUp(heap.size()-1);
        }
        else{
            if(val>heap[0]){
                heap[0]=val;
                heapifyDown(0);
            }
        }
    }
    void heapifyUp(int i){
        while(i!=0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    void heapifyDown(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;
        if(left < heap.size() && heap[left] < heap[smallest]){
            smallest = left;
        }
        if(right < heap.size() && heap[right] < heap[smallest]){
            smallest = right;
        }
        if(smallest != i){
            swap(heap[smallest], heap[i]);
            heapifyDown(smallest);
        }
    }
    int getRoot(){
        return heap[0];
    }
};

class Solution{
    public:
    // O(nlogK) logk is for each element insertion in the minHeap
        int findKthLargest(vector<int>& nums, int k) {
            MinHeap h(k);
            for(int i=0;i<nums.size();i++){
                h.insert(nums[i]);
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
    cout<<s.findKthLargest(nums,k);
    return 0;
}