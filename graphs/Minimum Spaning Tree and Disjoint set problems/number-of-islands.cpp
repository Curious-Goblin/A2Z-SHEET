#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<int> par;
    vector<int> rank;
    int row, column,count;
    void construct(int n, int r, int c){
        rank.resize(n, 0);
        par.resize(n);
        for(int i=0;i<n;i++) par[i] = i;
        row = r, column = c, count = 0;
    }
    int id(int r, int c){
        return r*column + c;
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
        count--; 
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
        int k = operators.size();
        construct(n*m, n, m);
        vector<vector<int>> matrix(n, vector<int>(m,0));
        vector<int> output;
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<k;i++){
            int r = operators[i][0], c = operators[i][1];
            if(matrix[r][c]!=1){
                matrix[r][c] = 1;
                int id1 = id(r,c);
                count++;
                for(auto &dir:directions){
                    int nr = r + dir[0], nc = c + dir[1];
                    if(nr >=0 && nc >=0 && nr < n && nc < m && matrix[nr][nc]){
                        unionFind(id1, id(nr,nc));
                    }
                }
            }
            output.push_back(count);
        }
        return output;
    }
};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> operators(k, vector<int>(2));
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            cin>>operators[i][j];
        }
    }
    Solution sol;
    vector<int> result = sol.numOfIslands(n, m, operators);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}