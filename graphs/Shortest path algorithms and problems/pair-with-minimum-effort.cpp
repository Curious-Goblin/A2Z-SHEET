#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int rows = heights.size(), columns = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> effort(rows, vector<int>(columns, INT_MAX));
        pq.push({0,{0,0}});
        effort[0][0]=0;
        while(!pq.empty()){
            int currEffort = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            int r = node.first, c = node.second;
            if(r == rows-1 && c == columns-1){
                return currEffort;
            }
            for(auto &dir : directions){
                int  nr = r + dir[0], nc = c + dir[1];
                if(nr >= 0 && nc >= 0 && nr < rows && nc < columns){
                    int nextEffort = max(currEffort, abs(heights[nr][nc]-heights[r][c]));
                    if(nextEffort<effort[nr][nc]){
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<int>> heights(rows, vector<int>(columns));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>heights[i][j];
        }
    }
    Solution sol;
    cout<<sol.minimumEffortPath(heights)<<endl;
    return 0;
}