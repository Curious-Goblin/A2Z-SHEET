#include "iostream"
#include "vector"

using namespace std;

vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    int floor = -1, ciel = 1000001;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= x && arr[i] > floor)
        {
            floor = arr[i];
        }
        if (arr[i] >= x && arr[i] < ciel)
        {
            ciel = arr[i];
        }
    }
    if (ciel == 1000001)
    {
        ciel = -1;
    }
    result.push_back(floor);
    result.push_back(ciel);
    return result;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result = getFloorAndCeil(x, arr);
    for (int i = 0; i < 2; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}