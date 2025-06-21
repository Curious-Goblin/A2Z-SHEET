#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>>& adj) {
        vector<vector<pair<int,int>>> adlist(V);
        int u,v,w;
        for(int i=0;i<adj.size();i++){
            u=adj[i][0],v=adj[i][1],w=adj[i][2];
            adlist[u].push_back({v,w});
            adlist[v].push_back({u,w});
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<bool> visited(V, false);
        int tWeight = 0;
        pq.push({0,0,-1});
        while(!pq.empty()){
            auto element = pq.top();
            pq.pop();
            int weight = get<0>(element);
            int node = get<1>(element);
            int parent = get<2>(element);
            if(!visited[node]){
                visited[node] = true;
                for(auto &it:adlist[node]){
                    int next = it.first;
                    int nextW = it.second;
                    if(!visited[next]){
                        pq.push({nextW, next, node});
                    }
                }
                if(parent == -1){
                    continue;
                }
                else{
                    tWeight += weight;
                }
            }
        }
        return tWeight;
    }
};

int main(){
    int V, e;
    cin>>V>>e;
    vector<vector<int>> adjoint(e,vector<int>(3));
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>adjoint[i][j];
        }
    }
    Solution sol;
    cout<<sol.spanningTree(V, adjoint);
    return 0;
}