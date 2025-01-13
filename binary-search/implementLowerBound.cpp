#include "iostream"
#include "vector"

using namespace std;

int findFloor(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] <= k)
        {
            low = mid + 1;
        }
        else if (arr[mid] >= k)
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = findFloor(arr, k);
    cout << result;
    return 0;
}