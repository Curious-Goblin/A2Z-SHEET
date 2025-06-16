#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
        bool dfsCheck(vector<vector<int>>& graph, vector<int>& color, int x, int currentColor){
            color[x] = currentColor;
            for(int &it:graph[x]){
                if(color[it]==-1){
                    if(!dfsCheck(graph, color, it, 1 - currentColor)) return false;
                }
                else if(color[it]==currentColor){
                    return false;
                }
            }

            return true;
        }
        bool isBipartite(vector<vector<int>>& graph){
            int vertices = graph.size();
            vector<int> color(vertices, -1); // -1 : no color, 0 or 1 different colors
            for(int i=0;i<vertices;i++){
                if(color[i]==-1){
                    if(!dfsCheck(graph, color, i, 0)) return false;
                }
            }
            return true;
        }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n);

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor);
        }
    }

    Solution sol;
    cout <<sol.isBipartite(graph)<< endl;

    return 0;
}
