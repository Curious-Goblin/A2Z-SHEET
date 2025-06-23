#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<int> par;
    vector<int> rank;
    void construct(int n){
        rank.resize(n, 0);
        par.resize(n);
        for(int i=0;i<n;i++) par[i] = i;
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    void unionFind(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        else{
            if(rank[pu] < rank[pv]) par[pu] = pv;
            else if(rank[pu] > rank[pv]) par[pv] = pu;
            else {
                par[pv] = pu;
                rank[pu]++;
            }
        } 
    }
    int removeStones(vector<vector<int>> &stones){
        int n = stones.size();
        construct(n);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(stones[i][0]==stones[j][0]){
        //             unionFind(i, j);
        //         }
        //         else if(stones[i][1] == stones[j][1]){
        //             unionFind(i, j);
        //         }
        //     }
        // }

        unordered_map<int,vector<int>> rowMap, colMap;
        for(int i=0;i<n;i++){
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }
        for(auto &it : rowMap){
            auto &indices = it.second;
            for(int i = 1; i < (int)indices.size(); i++){
                unionFind(indices[0], indices[i]);
            }
        }

        for(auto &it : colMap){
            auto &indices = it.second;
            for(int i = 1; i < (int)indices.size(); i++){
                unionFind(indices[0], indices[i]);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(par[i]==i) count++;
        }
        if(count < n) return n-count;
        return 0;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> stones(n, vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>stones[i][j];
        }
    }
    Solution sol;
    cout<<sol.removeStones(stones);
    return 0;
}