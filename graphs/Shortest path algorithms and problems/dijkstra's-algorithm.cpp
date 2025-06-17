#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<vector<pair<int,int>>> buildAdList(int V, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> result(V);
        for(auto &it:edges){
            result[it[0]].push_back({it[1],it[2]});
            result[it[1]].push_back({it[0],it[2]});
        }
        return result;
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) { 
        vector<vector<pair<int,int>>> adlist = buildAdList(V, edges);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(V, false);
        pq.push({0,src});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            visited[node] = true;
            pq.pop();
            for(auto &it:adlist[node]){
                if(!visited[it.first]){
                    int adjNode = it.first;
                    int weight = it.second;
                    if(dist[adjNode] > d + weight){
                        dist[adjNode] = d + weight;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
        }       
        return dist;
    }
};

int main(){
    int V, E, src;
    cin >> V >> E >> src;
    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution sol;
    vector<int> result = sol.dijkstra(V, edges, src);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}