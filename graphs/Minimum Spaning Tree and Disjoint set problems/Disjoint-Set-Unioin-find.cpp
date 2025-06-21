#include <iostream>
#include <vector>

using namespace std;

class DSU{
    public:
    vector<int> rank,par,size;
    DSU(int n){
        rank.resize(n,0);
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unionSetRank(int x, int z)
    {
        int px = find(x);
        int pz = find(z);
        if(rank[px] < rank[pz]) par[px] = pz;
        else if(rank[pz] < rank[px]) par[pz] = px;
        else {
            par[px] = pz;
            rank[pz]++;
        }
    }
    void unionSetSize(int x, int z){
        int px = find(x);
        int pz = find(z);
        if(size[px] < size[pz]) {
            par[px] = pz;
            size[pz] += size[px];
        }
        else if(size[px] > size[pz]){
            par[pz] = px;
            size[px] += size[pz];
        }
        else{
            par[px] = pz;
            size[pz] += size[px];
        }
        
    }
};