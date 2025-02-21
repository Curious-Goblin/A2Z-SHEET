#include "bits/stdc++.h"

using namespace std;


/*
here we are comparing the parent node with its child nodes
*/ 
class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    Solution solve;
    cout << solve.isMaxHeap(arr, n);
    return 0;
}