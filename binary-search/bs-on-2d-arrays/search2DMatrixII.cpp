#include "iostream"
#include "vector"

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row=0,column=matrix[0].size()-1;
    while(row<=matrix.size()-1 && column<=matrix[0].size()-1){
        if(matrix[row][column]==target){
            return true;
        }
        else if(matrix[row][column]>target){
            column--;
        }
        else if(matrix[row][column]<target){
            row++;
        }
    }
    return false;
}

int main()
{
    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    bool result = searchMatrix(matrix, target);
    cout << result;
    return 0;
}