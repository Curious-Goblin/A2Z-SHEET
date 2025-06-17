#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    bool dfs(vector<vector<int>> &graph, vector<int> &safeNodes, vector<int> &visited, vector<bool> &restack, int node){
        visited[node] = 1;
        restack[node] = true;
        if(graph[node].empty()){
            visited[node] = 2;
            safeNodes.push_back(node);
            return true;
        }
        for(int &x : graph[node]){
            if(!visited[x]){
                if(!dfs(graph, safeNodes, visited, restack, x)){
                    restack[node] = false;
                    return false;
                }
            }
            else if(visited[x] == 1 && restack[x]){
                restack[node] = false;
                return false;
            }
            else if(visited[x] != 2){
                restack[node] = false;
                return false;
            }
        }

        visited[node] = 2;
        safeNodes.push_back(node);
        restack[node] = false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph){
        vector<int> safeNodes;
        int v = graph.size();
        vector<int> visited(v, 0);
        vector<bool> restack(v, false);
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                dfs(graph, safeNodes, visited, restack, i);
            }
        }
        safeNodes = {};
        for(int i=0;i<v;i++){
            if(visited[i]==2){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

int main(){
    int n, r;
    cin >> n;
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
    vector<int> result = sol.eventualSafeNodes(adj);
    for(int &x:result){
        cout<<x<<" ";
    }
    return 0;
}