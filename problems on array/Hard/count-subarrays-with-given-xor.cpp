#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
// complexity is O(N) O(NlogN) depending upon whhat time your map is taking to do the operations.
    long subarrayXor(vector<int> &arr, int k)
    {
        int prefix = 0;
        long count = 0;
        unordered_map<int, int> cumulativeXor;
        cumulativeXor[0] = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            prefix = prefix ^ arr[i];
            int x = prefix ^ k;
            count += cumulativeXor[x];
            cumulativeXor[prefix]++;
        }
        return count;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    long result = s.subarrayXor(arr, k);
    cout << result;
    return 0;
}