#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adlist(n+1);
        for(int i=0;i<times.size();i++){
            adlist[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> effort(n+1, INT_MAX);
        effort[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int currEffort = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it:adlist[node]){
                int next = it.first;
                int delay = it.second;
                if(effort[next] > currEffort + delay){
                    effort[next] = currEffort + delay;
                    pq.push({effort[next], next});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<effort.size();i++){
            ans = max(effort[i],ans);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

int main(){
    int n, edges, k;
    cin>>n>>edges>>k;
    vector<vector<int>> times(edges, vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>times[i][j];
        }
    }
    Solution sol;
    cout<<sol.networkDelayTime(times, n, k);
    return 0;
}