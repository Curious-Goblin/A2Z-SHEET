#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> events;
        for(int i=0;i<arr.size();i++){
            events.push({arr[i],0});
            events.push({dep[i],1});
        }
        int count = 0, max_count = 0;
        while(!events.empty()){
            if(events.top().second == 0){ 
                count++;
            }
            else if(events.top().second == 1){
                count--;
            }
            events.pop();
            max_count = max(count, max_count);
        }
        return max_count;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n), dep(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>dep[i];
    }
    Solution s;
    cout<<s.findPlatform(arr,dep);
    return 0;
}