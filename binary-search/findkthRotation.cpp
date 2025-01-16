#include "iostream"
#include "vector"

using namespace std;

int findKRotation(vector<int> &arr)
{
    int high = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[high])
        {
            high = i;
        }
    }
    if (high == arr.size() - 1)
    {
        return 0;
    }
    return high + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = findKRotation(arr);
    cout << result;
    return 0;
}