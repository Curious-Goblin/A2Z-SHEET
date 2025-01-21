#include "iostream"
#include "vector"
#include "numeric"
#include "bits/stdc++.h"

using namespace std;

int countNumberOfStudents(vector<int> &arr, int pages)
{
    int student = 1, pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            student++;
            pagesStudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    // int high = *max_element(arr.begin(), arr.end()), sum = accumulate(arr.begin(), arr.end(), 0);
    // for (int i = high; i <= sum; i++)
    // {
    //     int student = countNumberOfStudents(arr, i);
    //     if (student == m)
    //     {
    //         return i;
    //     }
    // }
    int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0), mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int student = countNumberOfStudents(arr, mid);
        if (student <= m)
        {
            high = mid - 1;
        }
        else if (student > m)
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = findPages(arr, n, m);
    cout << result;
    return 0;
}