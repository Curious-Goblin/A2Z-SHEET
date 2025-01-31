#include "iostream"
#include "vector"

using namespace std;

int maxElementIndex(vector<vector<int>> &mat, int mid)
{
    int max = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][mid] > mat[max][mid])
        {
            max = i;
        }
    }
    return max;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int low, high, mid, row, left, right;
    low = 0, high = mat[0].size() - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        row = maxElementIndex(mat, mid);
        left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        right = mid + 1 < mat[row].size() ? mat[row][mid + 1] : -1;
        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            return {row, mid};
        }
        else if (mat[row][mid] < left)
        {
            high = mid - 1;
        }
        else if (mat[row][mid] < right)
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
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