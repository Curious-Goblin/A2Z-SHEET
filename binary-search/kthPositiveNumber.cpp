#include "iostream"
#include "vector"

using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1, missing, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low + k;
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
    int result = findKthPositive(arr, k);
    cout << result;
    return 0;
}