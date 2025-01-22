#include "iostream"
#include "vector"
#include "bits/stdc++.h"

using namespace std;

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end()), high = accumulate(boards.begin(), boards.end(), 0), mid, painters, time;
    while (low <= high)
    {
        mid = (low + high) / 2;
        painters = 1, time = 0;
        for (int i = 0; i < boards.size(); i++)
        {
            if (time + boards[i] <= mid)
            {
                time += boards[i];
            }
            else
            {
                painters++;
                time = boards[i];
            }
        }
        if (painters <= k)
        {
            high = mid - 1;
        }
        else if (painters > k)
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> boards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> boards[i];
    }
    int result = findLargestMinDistance(boards,k);
    cout<<result;
    return 0;
}