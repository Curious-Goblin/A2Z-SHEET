#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
       int rows = mat.size(), columns = mat[0].size();
       queue<pair<pair<int,int>,int>> qu;
       vector<vector<bool>> visited(rows, vector<bool>(columns, false));
       for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==0){
                qu.push({{i,j},0});
                visited[i][j] = true;
            }
        }
       }

       vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

       while(!qu.empty()){
        auto node = qu.front().first;
        auto dist = qu.front().second;
        int r = node.first;
        int c = node.second;
        qu.pop();

        for(auto &[dr, dc] : directions){
            int nr = r+dr, nc = c+dc;
            if(nr>=0 && nc>=0 && nr<rows && nc<columns && !visited[nr][nc]){
                mat[nr][nc] = dist+1;
                visited[nr][nc] = true;
                qu.push({{nr,nc}, dist+1});
            }
        }
       }
       return mat;
    }
};

int main(){
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<int>> grid(rows, vector<int>(columns));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>grid[i][j];
        }
    }

    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(grid);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}