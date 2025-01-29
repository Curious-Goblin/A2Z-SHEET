#include "iostream"
#include "vector"

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int left = 0, right = matrix.size() - 1, middle;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (matrix[middle][0] <= target && target <= matrix[middle].back())
        {
            int low = 0, high = matrix[middle].size() - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (matrix[middle][mid] == target)
                {
                    return true;
                }
                else if (matrix[middle][mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return false;
        }

        if (matrix[middle][0] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
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