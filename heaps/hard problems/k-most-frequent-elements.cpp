#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    // O(NlogN)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        // O(n)
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> frequent;

        for(auto it = hash.begin(); it!= hash.end(); ++it){
            if(it->second != 0){
                frequent.push({it->second,it->first});
            }
        }
        vector<int> result;
        while(result.size()!=k && !frequent.empty()){
            result.push_back(frequent.top().second);
            frequent.pop();
        }
        return result;
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
    vector<int> result = s.topKFrequent(nums, k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}