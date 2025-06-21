#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adlist(n);
        for(int i=0;i<roads.size();i++){
            adlist[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adlist[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq;
        pq.push({0,0});
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n,0);
        ways[0]=1;
        const int MOD = 1e9 + 7;
        while(!pq.empty()){
            long long int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(currDist > dist[node]) continue;
            for(auto &it:adlist[node]){
                int next = it.first;
                int nextDist = it.second;
                if(currDist + nextDist < dist[next]){
                    dist[next] = currDist + nextDist;
                    ways[next] = ways[node];
                    pq.push({dist[next],next});
                }
                else if(currDist + nextDist == dist[next]){
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};

int main(){
    int n, edges;
    cin>>n>>edges;
    vector<vector<int>> times(edges, vector<int>(3));
    for(int i=0;i<edges;i++){
        for(int j=0;j<3;j++){
            cin>>times[i][j];
        }
    }
    Solution sol;
    cout<<sol.countPaths(n, times);
    return 0;
}