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

    bool dfsCycleCheck(int start, vector<vector<int>>& adList, vector<bool> &visited, int parent){
        visited[start] = true;

        for(int x:adList[start]){
            if(!visited[x]){
                if(dfsCycleCheck(x, adList, visited, start)){
                    return true;
                }
            }
            else if(x != parent){
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges){
        vector<vector<int>> adList = adjacencyList(V, edges);
        vector<bool> visited(V, false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfsCycleCheck(i, adList, visited, -1)){
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