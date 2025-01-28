#include "iostream"
#include "vector"

using namespace std;

int rowWithMax1s(vector<vector<int>> &arr)
{
    int ones = 0, row = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int low = 0, high = arr[i].size() - 1, mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[i][mid] == 1)
            {
                high = mid - 1;
            }
            else if (arr[i][mid] == 0)
            {
                low = mid + 1;
            }
        }
        if (arr[i].size() - low > ones)
        {
            ones = arr[i].size() - low;
            row = i;
        }
    }
    if (ones == 0 && row == 0 && arr[0][0] != 1)
    {
        return -1;
    }
    return row;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int result = rowWithMax1s(arr);
    cout << result;
    return 0;
}