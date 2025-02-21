#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int i=0,j=0;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    Solution solve;
    cout<<solve.maxMeetings(start,end);
    return 0;
}