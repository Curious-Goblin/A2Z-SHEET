#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    
}

int main()
{
    int n, target, sample;
    cin >> n;
    cin >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> sample;
        nums.push_back(sample);
    }
    auto result = searchRange(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}