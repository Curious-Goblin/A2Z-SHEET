#include "iostream"
#include "vector"

using namespace std;

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<int> result = findPeakGrid(mat);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}