#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int orangesRotting(vector<vector<int>>& grid){
        queue<pair<pair<int,int>,int>> qu;
        int time=0,rows = grid.size(), column = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(column, false));

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    qu.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();

            time = max(time, node.second);

            auto point = node.first;
            int i=point.first, j=point.second;

            if(i+1<rows && grid[i+1][j] == 1 && !visited[i+1][j]){
                qu.push({{i+1,j},node.second+1});
                visited[i+1][j] = true;
            }
            if(i-1>=0 && grid[i-1][j] == 1 && !visited[i-1][j]){
                qu.push({{i-1,j}, node.second+1});
                visited[i-1][j] = true;
            }
            if(j+1<column && grid[i][j+1] == 1 && !visited[i][j+1]){
                qu.push({{i,j+1}, node.second + 1});
                visited[i][j+1] = true;
            }
            if(j-1>=0 && grid[i][j-1] == 1 && !visited[i][j-1]){
                qu.push({{i,j-1},node.second + 1});
                visited[i][j-1] = true;
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return time;
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
    cout<<sol.orangesRotting(grid)<<endl;
    return 0;
}