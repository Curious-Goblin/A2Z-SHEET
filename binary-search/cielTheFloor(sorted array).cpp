#include "iostream"
#include "vector"

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1, mid, floor = 0, ciel = 1000000001;
    pair<int, int> result;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] <= x)
        {
            low = mid + 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
    }
    floor = -1;
    if (high != -1)
    {
        floor = a[high];
    }
    low = 0, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] >= x)
        {
            high = mid - 1;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
    }
    ciel = -1;
    if (low != n)
    {
        ciel = a[low];
    }
    result.first = floor;
    result.second = ciel;
    return result;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> result = getFloorAndCeil(a, n, x);
    cout << result.first << " " << result.second;
    return 0;
}