#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:

    // time complexity O(n*k*4^l) space complexity = O(n*m + L)
    // we cannot start from 0,0 and search the matrix row by row and column by column and if we did
    // we will only be correct in the cases where we get the word starting from the first letter 
    // because dfs
    // says that you need to start all the way fresh from the top if the current path fails so we
    // need to externally implement a loop which will traverse the matrix and give us the starting 
    // point and we also need to maintain a visited matrix to check if we are counting the same
    // indices twice.
    void helper(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int index, int row, int coloumn, bool &result){
        if(index == word.size()){
            result = true;
            return;
        }
        if(row >= board.size() || coloumn >= board[0].size() || row < 0 || coloumn < 0){
            return;
        }
        if (visited[row][coloumn] || board[row][coloumn] != word[index]){
            return;
        }
    
        visited[row][coloumn] = true;
    
        helper(board, visited, word, index+1, row, coloumn+1, result);
        helper(board, visited, word, index+1, row, coloumn-1, result);
        helper(board, visited, word, index+1, row+1, coloumn, result);
        helper(board, visited, word, index+1, row-1, coloumn, result);
    
        visited[row][coloumn] = false;
    }
    
    bool exist(vector<vector<char>> &board, string word){
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    bool result = false;
                    helper(board, visited, word, 0, i, j, result);
                    if(result) return true;
                }
            }
        }
        return false;
    }
    
};

int main(){
    int n,m;
    cin>>n>>m;
    string word;
    cin>>word;
    vector<vector<char>> board;
    for(int i=0;i<n;i++){
        vector<char> temp(m);
        for(int j=0;j<m;j++){
            cin>>temp[j];
        }
        board.push_back(temp);
    }
    Solution s;
    bool result = s.exist(board, word);
    cout<<result;
}