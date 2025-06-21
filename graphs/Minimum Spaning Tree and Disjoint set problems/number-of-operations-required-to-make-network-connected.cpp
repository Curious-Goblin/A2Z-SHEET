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
    int makeConnected(int n, vector<vector<int>>& connections) {
        construct(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0], v = connections[i][1];
            int pu = find(u), pv = find(v);
            if(pu!=pv){
                unionn(pu, pv);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(par[i]==i){
                count++;
            }
        }

        if(connections.size()<n-1){
            return -1;
        }
        return count-1;
    }
};

int main(){
    int n,a;
    cin>>n>>a;
    vector<vector<int>> connections(a, vector<int>(2));
    for(int i=0;i<a;i++){
        for(int j=0;j<2;j++){
            cin>>connections[i][j];
        }
    }
    Solution sol;
    cout<<sol.makeConnected(n, connections);
    return 0;
}