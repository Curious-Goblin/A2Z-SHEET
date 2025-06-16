#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    void recursive(vector<vector<int>>& grid, vector<pair<int,int>>& directions, int i, int j){
        int rows = grid.size(), columns = grid[0].size();
        for(auto it:directions){
            int dr = it.first, dc = it.second, nr = i+dr, nc = j+dc;
            if(nr >= 0 &&  nc >= 0 && nr < rows && nc < columns){
                if(grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    recursive(grid, directions, nr, nc);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid){
        int rows = grid.size(), columns = grid[0].size();
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> qu;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i == 0 || i== rows-1 || j == 0 || j == columns-1){
                    if(grid[i][j]==1){
                        qu.push({i,j});
                    }
                }
            }
        }
        while(!qu.empty()){
            int r = qu.front().first, c = qu.front().second;
            qu.pop();
            grid[r][c] = 2;
            recursive(grid, directions, r, c);
        }
        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
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
    cout<<sol.numEnclaves(grid)<<endl;
    return 0;
}