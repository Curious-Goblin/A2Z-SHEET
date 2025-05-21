#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
        // the complexity if n*k and it is not optimal
        // void nearlySorted(vector<int>& arr, int k) {
        //     for(int i=0;i<arr.size();i++){
        //         int a = 0;
        //         int largest = i;
        //         while(a!=k){
        //             int index = i-a-1;
        //             if(index >= 0 && arr[index] > arr[largest]){
        //                 largest = index;
        //             }
        //             a++;
        //         }
        //         if(largest != i){
        //             swap(arr[largest],arr[i]);
        //         }
        //         else{
        //             a = 0;
        //             int smallest = i;
        //             while(a != k){
        //                 int index = i + a + 1;
        //                 if(index < arr.size() && arr[index] < arr[smallest]){
        //                     smallest = index;
        //                 }
        //                 a++;
        //             }
        //             if(smallest != i){
        //                 swap(arr[smallest], arr[i]);
        //             }
        //         }
        //     }
        // }

        // this is the optimal approach and it has much O(nlogk) complexity;
        void nearlySorted(vector<int>& arr, int k) {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            int index = 0;
            for(int i = 0; i < k + 1; i++){
                minHeap.push(arr[i]);
            }
            for(int i = k+1; i < arr.size(); i++){
                arr[index++] = minHeap.top();
                minHeap.pop();
                minHeap.push(arr[i]);
            }
            while(!minHeap.empty()){
                arr[index++] = minHeap.top();
                minHeap.pop();
            }
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
    s.nearlySorted(nums,k);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}