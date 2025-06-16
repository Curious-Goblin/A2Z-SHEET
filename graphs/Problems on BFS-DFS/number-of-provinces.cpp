#include "bits/stdc++.h"

using namespace std;

class DSU{
    public:
    vector<int> parent,size;

    DSU(int n){
        parent.resize(n);
        size.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int a){
        if(parent[a]==a) return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;

        else{
            if(size[pa]<size[pb]) swap(pa,pb);
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
    }
};

class Solution{
    public:
    int findCircleNum(vector<vector<int>>& isConnected){
        DSU dsu(isConnected.size());

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    dsu.unite(i,j);
                }
            }
        }

        unordered_map<int, vector<int>> provinces;
        for(int i=0;i<isConnected.size();i++){
            provinces[dsu.find(i)].push_back(i);
        }

        return provinces.size();
    }
};

int main(){
    int row, column;
    cin>>row>>column;
    vector<vector<int>> isConnected(row, vector<int>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>isConnected[i][j];
        }
    }
    Solution sol;
    cout<<sol.findCircleNum(isConnected)<<endl;
    return 0;
}