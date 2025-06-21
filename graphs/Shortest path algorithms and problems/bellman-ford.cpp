#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 100000000;
        vector<int> dist(V, INF);
        dist[src] = 0;

        for(int i = 0; i < V-1; ++i) {
            for(auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        for(int i = 0; i < V; ++i) {
            if(dist[i] == INF) {
                dist[i] = 100000000;
            }
        }

        return dist;
    }
};

int main() {
    int v, e, src;
    cin >> v >> e >> src;

    vector<vector<int>> edges(e, vector<int>(3));
    for(int i = 0; i < e; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> edges[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.bellmanFord(v, edges, src);
    for(int i = 0; i < (int)result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
