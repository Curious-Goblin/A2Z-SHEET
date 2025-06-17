#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src){
        vector<int> paths(adj.size(), -1);
        vector<bool> visited(adj.size(), false);
        queue<int> qu;
        qu.push(src);
        unordered_map<int,int> map;
        map[src] = 0;
        visited[src] = true;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            int dist = map[node];
            for(int &a:adj[node]){
                if(!visited[a]){
                    qu.push(a);
                    map[a] = dist+1;
                    visited[a] = true;
                }
                else{
                    map[a] = min(map[a], dist+1);
                }
            }
        }
        for(auto &it:map){
            paths[it.first] = it.second;
        }
        return paths;
    }
};

int main(){
    int n, r, src;
    cin >> n >> src;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        vector<int> temp(r);
        for (int j = 0; j < r; j++)
        {
            cin >> temp[j];
        }
        adj.push_back(temp);
    }

    Solution sol;
    vector<int> result = sol.shortestPath(adj, src);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}