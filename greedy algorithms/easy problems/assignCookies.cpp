#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s) // two pointer approach works without sorting if for g and s are already sorted.
    {
        int count = 0;
        int i = 0, j = 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g(n), s(m);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }
    Solution sol;
    cout << sol.findContentChildren(g, s);
}