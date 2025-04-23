#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
    // O(4^(n*m)) and space is O(n*m +(paths)(length of paths))
    void helper(vector<vector<int>> &mat, vector<string> &result, string &path, vector<vector<bool>> &visited, int row, int column){
        if(row >= mat.size() || column >= mat[0].size() || row < 0 || column < 0 || visited[row][column] || mat[row][column] == 0){
            return;
        }
        if(row == mat.size()-1 && column == mat[0].size()-1){
            result.push_back(path);
            return;
        }
        visited[row][column] = true;
        path+='D';
        helper(mat, result, path, visited, row + 1, column);
        path.pop_back();
        path+='U';
        helper(mat, result, path, visited, row - 1, column);
        path.pop_back();
        path+='R';
        helper(mat, result, path, visited, row, column + 1);
        path.pop_back();
        path+='L';
        helper(mat, result, path, visited, row, column - 1);
        path.pop_back();
        visited[row][column] = false;
    }
    vector<string> findPath(vector<vector<int>> &mat){
        if(mat[0][0]==0){
            return {};
        }
        vector<string> result;
        string path;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(),false));
        helper(mat, result, path, visited, 0, 0);
        return result;
    }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    Solution s;
    vector<string> result = s.findPath(mat);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}