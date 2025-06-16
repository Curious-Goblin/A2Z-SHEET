#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    void recursive(vector<vector<char>>& board, vector<pair<int,int>>& directions, int i, int j){
        int rows = board.size(), columns = board[0].size();
        for(auto &it:directions){
            int dr = it.first, dc = it.second, nr = i+dr, nc = j+dc;
            if(nr >= 0 && nc >= 0 && nr < rows && nc < columns){
                if(board[nr][nc]=='O'){
                    board[nr][nc]='S';
                    recursive(board, directions, nr, nc);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board){
        queue<pair<int,int>> qu;
        int rows = board.size(), columns = board[0].size();
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i == 0 || i== rows-1 || j == 0 || j == columns-1){
                    if(board[i][j]=='O'){
                        qu.push({i,j});
                    }
                }
            }
        }
        while(!qu.empty()){
            int r = qu.front().first, c = qu.front().second;
            qu.pop();
            board[r][c] = 'S';
            recursive(board, directions, r, c);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(board[i][j]=='S'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(){
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<char>> board(rows, vector<char>(columns));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>board[i][j];
        }
    }
    Solution sol;
    sol.solve(board);
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}