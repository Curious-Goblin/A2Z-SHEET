#include "bits/stdc++.h"

using namespace std;

class Solution {
    public:
    void maxHeapify(int i, vector<int> &arr, int N){
      int left = 2*i + 1;
      int right = 2*i + 2;
      int largest = i;
      if(left < N && arr[left] > arr[largest])
        largest = left;
      if(right < N && arr[right] > arr[largest])
        largest = right;
      if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(largest, arr, N);
      }
    }
    // O(NlogN)
    void convertMinToMaxHeap(vector<int> &arr, int N) {
      int i = (N/2) - 1;
      for(;i>=0;i--){
        maxHeapify(i, arr, N);
      }
    }
  };
  

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
      cin>>nums[i];
    }
    Solution s;
    s.convertMinToMaxHeap(nums,n);
    for(int i=0;i<n;i++){
      cout<<nums[i]<<" ";
    }
    return 0;
}