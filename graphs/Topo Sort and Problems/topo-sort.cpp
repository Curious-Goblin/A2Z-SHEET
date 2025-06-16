#include "bits/stdc++.h"

using namespace std;

class Solution{
    private:
    void dfs(int node, vector<vector<int>>& adlist, vector<bool>& visited, stack<int> &st){
        visited[node] = true;
        for(int &it:adlist[node]){
            if(!visited[it]){
                dfs(it, adlist, visited, st);
            }
        }
        st.push(node);
    }
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
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> result;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, adlist, visited, st);
            }
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
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