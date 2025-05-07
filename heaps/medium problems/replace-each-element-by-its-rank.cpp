#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        unordered_map<int,int> map;
        for(int i=0; i<N; i++){
            minHeap.push(arr[i]);
        }
        int i = 1;
        while(!minHeap.empty()){
            auto it = map.find(minHeap.top());
            if(it!=map.end()){
                minHeap.pop();
                continue;
            }
            map[minHeap.top()] = i;
            i++;
            minHeap.pop();
        }
        for(int i=0; i<N; i++){
            auto it = map.find(arr[i]);
            arr[i] = it->second;
        }
        return arr;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    Solution s;
    s.replaceWithRank(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}