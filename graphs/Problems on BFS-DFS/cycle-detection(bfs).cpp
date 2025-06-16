#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:

    vector<vector<int>> adjacencyList(int V, vector<vector<int>>& edges){
        vector<vector<int>> list(V);
        map<int, set<int>> adlist;

        for(int i=0;i<edges.size();i++){
            adlist[edges[i][0]].insert(edges[i][1]);
            adlist[edges[i][1]].insert(edges[i][0]);
        }

        for(auto &it:adlist){
            list[it.first] = vector<int>(it.second.begin(), it.second.end());
        }

        return list;
    }

    bool bfsCycleCheck(int start, vector<vector<int>>&  adList, vector<bool>& visited){
        queue<pair<int,int>> qu; // {node, parent}
        qu.push({start, -1});
        visited[start] = true;

        while(!qu.empty()){
            int node = qu.front().first;
            int parent = qu.front().second;
            qu.pop();

            for(int neighbour : adList[node]){
                if(!visited[neighbour]){
                    qu.push({neighbour,node});
                    visited[neighbour] = true;
                }
                else if(neighbour != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges){
        vector<vector<int>> adList = adjacencyList(V, edges);
        vector<bool> visited(V, false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfsCycleCheck(i, adList, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int vertices;
    cin >> vertices;
    int edge;
    cin >> edge;
    vector<vector<int>> edges(edge, vector<int>(2));
    int a = 0, b = 0;
    for (int i = 0; i < edge; i++) {
        cin >> a >> b;
        edges[i] = {a, b};
    }

    Solution sol;
    cout<<sol.isCycle(vertices, edges)<<endl;
    return 0;
}