#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int merge(vector<int> &arr, int left, int mid, int right)
    {
        int count = 0;
        vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
                count += mid - i + 1;
            }
        }
        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <=right)
            temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++)
        {
            arr[left + k] = temp[k];
        }
        return count;
    }
    int mergeSort(vector<int> &arr, int left, int right)
    {
        int count = 0;
        if (left < right)
        {
            int mid = (left + right) / 2;
            count += mergeSort(arr, left, mid);
            count += mergeSort(arr, mid + 1, right);
            count += merge(arr, left, mid, right);
        }
        return count;
    }
    int inversionCount(vector<int> &arr)
    {
        int count = mergeSort(arr,0,arr.size()-1);
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    int result = s.inversionCount(arr);
    cout << result;
    return 0;
}