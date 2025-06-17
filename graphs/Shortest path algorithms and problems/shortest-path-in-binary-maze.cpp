#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    // using dijkstra
    int shortestPathBinaryMatrix2(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]) return -1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false)); 
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            int r = node.first, c = node.second;
            if(r==n-1 && c==n-1){
                return d;
            }
            visited[r][c] = true;
            for(auto &direc:directions){
                int dr = direc[0], dc = direc[1], nr = r + dr, nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < n && nc < n){
                    if(!visited[nr][nc] && grid[nr][nc] == 0){
                        if(dist[nr][nc] > d + 1){
                            dist[nr][nc] = d + 1;
                            pq.push({dist[nr][nc],{nr,nc}});
                        }
                    }
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]) return -1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false)); 
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        queue<pair<int,int>> qu;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        qu.push({0,0});
        dist[0][0]=1;
        visited[0][0] = true;
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();
            int r = node.first, c = node.second;
            int d = dist[r][c];
            if(r == n-1 && c == n-1){
                return d;
            }
            for(auto &dir : directions){
                int dr = dir[0], dc = dir[1], nr = r + dr, nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < n && nc < n){
                    if(!visited[nr][nc] && grid[nr][nc] == 0){
                        if(dist[nr][nc] > d + 1){
                            dist[nr][nc] = d + 1;
                            qu.push({nr,nc});
                            visited[nr][nc] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    Solution sol;
    cout<<sol.shortestPathBinaryMatrix(grid)<<endl;
    return 0;
}