// this is also the problem of determining the topological sort but through bfs approach

#include "bits/stdc++.h"

using namespace std;

class Solution{
    private:
    vector<vector<int>> buildAdList(int V, vector<vector<int>> &edges){
        map<int, set<int>> adlist;
        vector<vector<int>> result(V);

        for(int i=0;i<edges.size();i++){
            adlist[edges[i][0]].insert(edges[i][1]);
        }

        for(auto &it:adlist){
            result[it.first] = vector<int>(it.second.begin(), it.second.end());
        }
        return result;
    }
    public:
    vector<int> topoSort(int V, vector<vector<int>> &edges){
        vector<vector<int>> adlist = buildAdList(V, edges);
        queue<int> qu;
        vector<int> inDegree(V, 0);
        vector<int> result;
        for(int i=0;i<V;i++){
            for(int &neighbor:adlist[i]){
                inDegree[neighbor]++;
            }
        }
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            result.push_back(node);
            for(int& it:adlist[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    qu.push(it);
                }
            }
        }
        return result;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    vector<int> result = sol.topoSort(V, edges);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}