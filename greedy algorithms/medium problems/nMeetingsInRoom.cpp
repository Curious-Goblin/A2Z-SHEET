#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        if (start.size() == 1)
        {
            return 1;
        }
        int meetEnd = 0, meetings = 1;
        vector<pair<int, int>> meets;
        for (int i = 0; i < start.size(); i++)
        {
            meets.push_back({end[i], start[i]});
        }
        sort(meets.begin(), meets.end());
        meetEnd = meets[0].first;
        for (int i = 0; i < meets.size(); i++)
        {
            if (meets[i].second > meetEnd)
            {
                meetings++;
                meetEnd = meets[i].first;
            }
        }
        return meetings;
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
    // for(int i=0;i<n;i++){
    //     cout<<start[i]<<" ";
    // }
    // cout<<endl;
    Solution solve;
    cout << solve.maxMeetings(start, end);
    return 0;
}