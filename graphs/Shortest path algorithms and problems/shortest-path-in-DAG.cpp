#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    vector<vector<pair<int,int>>> list(int v, vector<vector<int>>& edges){
        map<int, set<pair<int,int>>> map;
        vector<vector<pair<int,int>>> result(v);

        for(int i=0;i<edges.size();i++){
            map[edges[i][0]].insert({edges[i][1], edges[i][2]});
        }

        for(auto &it:map){
            result[it.first] = vector<pair<int,int>>(it.second.begin(), it.second.end());
        }
        return result;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adlist = list(V, edges);
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &edges:adlist[node]){
                int adjNode = edges.first;
                int weight = edges.second;

                if(dist[adjNode]>d+weight){
                    dist[adjNode] = d+weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution sol;
    vector<int> result = sol.shortestPath(V, E, edges);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" "; 
    }
    return 0;
}