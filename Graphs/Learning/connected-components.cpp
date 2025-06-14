#include "bits/stdc++.h"

using namespace std;

class DSU {
    vector<int> parent, size;

    public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        // iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    // vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {
    //     vector<unordered_set<int>> components;
    //     vector<int> vertices(V, 0);

        // for(int i=0;i<edges.size();i++){
        //     if(edges[i][0]>edges[i][1]){
        //         swap(edges[i][0], edges[i][1]);
        //     }
        // }
        
        // sort(edges.begin(), edges.end());

    //     components.push_back({edges[0][0], edges[0][1]});
    //     vertices[edges[0][0]] = 1;
    //     vertices[edges[0][1]] = 1;

    //     for (int i = 1; i < edges.size(); i++) {
    //         vector<int> matched;
    //         for(int j=0;j<components.size();j++){
    //             if(components[j].count(edges[i][0]) || components[j].count(edges[i][1])){
    //                 matched.push_back(j);
    //             }
    //         }
    //         if(matched.empty()){
    //             components.push_back({edges[i][0], edges[i][1]});
    //             vertices[edges[i][0]] = 1;
    //             vertices[edges[i][1]] = 1;
    //         }
    //         else{
    //             int base = matched[0];
    //             components[base].insert(edges[i][0]);
    //             components[base].insert(edges[i][1]);

    //             vertices[edges[i][0]] = 1;
    //             vertices[edges[i][1]] = 1;

    //             for(int k=1;k<matched.size();k++){
    //                 int id = matched[k];
    //                 components[base].insert(components[id].begin(), components[id].end());
    //             }

    //             for(int k = matched.size()-1;k>=1;k--){
    //                 components.erase(components.begin() + matched[k]);
    //             }
    //         }
    //     }

    //     vector<vector<int>> result(components.size());
    //     int i = 0;
    //     for (auto it : components) {
    //         result[i] = vector<int>(it.begin(), it.end());
    //         i++;
    //     }

    //     int j = 0;
    //     for (auto it : vertices) {
    //         if (it == 0) {
    //             result.push_back({j});
    //         }
    //         j++;
    //     }

    //     return result;
    // }

    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges) {
        DSU dsu(V);

        for (auto &edge : edges) {
            dsu.unite(edge[0], edge[1]);
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < V; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        vector<vector<int>> result;
        for (auto &[_, group] : groups) {
            result.push_back(group);
        }

        return result;
    }
};



int main() {
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
    auto result = sol.getComponents(vertices, edges);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
