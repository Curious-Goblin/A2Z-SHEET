#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int countNodes(int i)
    {
        int nodes = pow(2, i - 1);
        return nodes;
    }
};

int main()
{
    int i;
    cin >> i;
    Solution solve;
    cout << solve.countNodes(i);
    return 0;
}