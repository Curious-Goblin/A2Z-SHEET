#include "bits/stdc++.h"
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
using namespace std;

class Solution{
    public:
    vector<vector<int>> list(int v, vector<vector<int>> &edges){
        map<int, set<int>> adlist;
        vector<vector<int>> result(v);

        for(int i=0;i<edges.size();i++){
            adlist[edges[i][0]].insert(edges[i][1]);
        }

        for(auto &it:adlist){
            result[it.first] = vector<int>(it.second.begin(), it.second.end());
        }
        return result;
    }
    bool dfsCycleCheck(int start, vector<vector<int>>& adList, vector<bool> &visited, vector<bool> &recstack){
        visited[start] = true;
        recstack[start] = true;

        for(int x:adList[start]){
            if(!visited[x]){
                if(dfsCycleCheck(x, adList, visited, recstack)){
                    return true;
                }
            }
            else if(recstack[x]){
                return true;
            }
        }

        recstack[start] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges){
        vector<vector<int>> adlist = list(V, edges);
        vector<bool> visited(V, false);
        vector<bool> recstack(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfsCycleCheck(i, adlist, visited, recstack)){
                    return true;
                }
            }
        }
        return false;
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
    cout<<sol.isCyclic(V, edges)<<endl;
    return 0;
}