#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    // vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    //     vector<pair<int,int>> jobs;
    //     for(int i=0;i<deadline.size();i++){
    //         jobs.push_back({profit[i],deadline[i]});
    //     }
    //     sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
    //     unordered_map<int,int> map;
    //     for(int i=0;i<jobs.size();i++){
    //         if(map.find(jobs[i].second) != map.end()){
    //             for(int j=(jobs[i].second)-1;j>0;j--){
    //                 if(map.find(j) == map.end()){
    //                     map[j] = jobs[i].first;
    //                     break;
    //                 }
    //             }
    //         }
    //         else{
    //             map[jobs[i].second] = jobs[i].first;
    //         }
    //     }
    //     vector<int> result = {map.size()};
    //     int sum = 0;
    //     for(auto &it:map){
    //         sum += it.second;
    //     }
    //     result.push_back(sum);
    //     return result;
    // }

    // O(NlogN + Max_deadline + findparent)

    int findParent(int slot, vector<int> &parent){
        if(parent[slot] == slot) return slot;
        return parent[slot] = findParent(parent[slot], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> jobs;
        int max_deadline = -1, count = 0, total_profit = 0;
        for(int i=0;i<deadline.size();i++){
            jobs.push_back({profit[i],deadline[i]});
            max_deadline = max(max_deadline, deadline[i]);
        }
        vector<int> parent(1 + max_deadline);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        for(auto &job:jobs){
            int availableSlot = findParent(job.second, parent);
            if(availableSlot > 0){
                count++;
                total_profit+=job.first;
                parent[availableSlot] = findParent(availableSlot-1, parent);
            }
        }
        return {count, total_profit};
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> deadline(n), profit(n);
    for(int i=0;i<n;i++){
        cin>>deadline[i];
    }
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    Solution s;
    vector<int> result = s.jobSequencing(deadline, profit);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}