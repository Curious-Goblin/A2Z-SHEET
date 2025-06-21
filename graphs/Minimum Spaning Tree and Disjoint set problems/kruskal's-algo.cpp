#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<int> par;
    vector<int> rank;
    void construct(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    void unionn(int x, int z){
        int px = find(x);
        int pz = find(z);
        if(rank[px] < rank[pz]){
            par[px] = pz; 
        }
        else if(rank[pz] < rank[px]){
            par[pz] = px;
        }
        else{
            par[pz] = px;
            rank[px]++;
        }
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        construct(V);
        sort(edges.begin(), edges.end(), 
        [](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });

        int tWeight = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            int pu = find(u), pv = find(v);
            if(pu!=pv){
                unionn(pu,pv);
                tWeight += w;
            }
        }
        return tWeight;
    }
};

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(e,vector<int>(3));
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>edges[i][j];
        }
    }
    Solution sol;
    cout<<sol.kruskalsMST(v, edges);
    return 0;
}