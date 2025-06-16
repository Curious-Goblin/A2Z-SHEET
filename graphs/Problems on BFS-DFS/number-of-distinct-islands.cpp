#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    void dfs(vector<vector<bool>>& visited, vector<pair<int,int>>& directions, vector<vector<int>>& grid, vector<pair<int,int>>& group, int& rows, int& columns, int i, int j){
        visited[i][j] = true;
        group.push_back({i,j});
        for(auto &it:directions){
            int dr = it.first, dc = it.second, nr = i + dr, nc = j + dc;
            if(nr >= 0 && nc >= 0 &&  nr < rows && nc < columns){
                if(grid[nr][nc] == 1 && !visited[nr][nc]){
                    dfs(visited, directions, grid, group, rows, columns, nr, nc);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid){
        int rows = grid.size(), columns = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        set<vector<pair<int,int>>> uniqueIslands;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    vector<pair<int,int>> island;
                    dfs(visited, directions, grid, island, rows, columns, i, j);

                    vector<pair<int,int>> normalized;
                    int baseR = island[0].first, baseC = island[0].second;
                    for(auto &p:island){
                        normalized.push_back({p.first - baseR, p.second - baseC});
                    }
                    uniqueIslands.insert(normalized);
                }
            }
        }
        return uniqueIslands.size();
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
    cout<<sol.countDistinctIslands(grid)<<endl;
    return 0;
}