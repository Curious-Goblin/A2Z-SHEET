#include "iostream"
#include "vector"

using namespace std;

int lowElementIndex(vector<vector<int>> &mat)
{
    int min = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][0] < mat[min][0])
        {
            min = i;
        }
    }
    return mat[min][0];
}

int maxElementIndex(vector<vector<int>> &mat)
{
    int max = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][mat.size() - 1] > mat[max][mat.size() - 1])
        {
            max = i;
        }
    }
    return mat[max][mat.size()-1];
}

int count(vector<vector<int>> &mat, int mid) // upper bound
{
    int low, high, middle, count = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        low = 0, high = mat[i].size() - 1;
        // cout<<"mid "<<mid<<endl;
        // cout<<"high "<<high<<endl;
        while (low <= high)
        {
            middle = (low + high) / 2;
            if (mat[i][middle] >= mid)
            {
                high = middle - 1;
            }
            else if (mat[i][middle] < mid)
            {
                low = middle + 1;
            }
        }
        count += low;
    }
    return count;
}

int median(vector<vector<int>> &mat)
{
    int low = lowElementIndex(mat), high = maxElementIndex(mat), mid, smallerEquals;
    // cout<<"low "<<low<<endl;
    // cout<<"high "<<high<<endl;
    while (low <= high)
    {
        mid = (low + high) / 2;
        smallerEquals = count(mat, mid);
        // cout<<smallerEquals<<endl;
        // cout<<"target "<<(mat.size()) * (mat[0].size()) / 2<<endl;
        if (smallerEquals <= (((mat.size()) * (mat[0].size())) / 2))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
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
    int result = median(mat);
    cout << result;
}