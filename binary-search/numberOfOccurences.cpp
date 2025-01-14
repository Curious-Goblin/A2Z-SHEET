#include "iostream"
#include "vector"

using namespace std;

int countFreq(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, mid, first = -1, last = 1000000001;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid]==target){
            first = mid;
            high = mid-1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid]==target){
            last = mid;
            low = mid+1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(first == -1 && last == 1000000001){
        return 0;
    }
    return last-first + 1;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = countFreq(arr, target);
    cout << result;
    return 0;
}