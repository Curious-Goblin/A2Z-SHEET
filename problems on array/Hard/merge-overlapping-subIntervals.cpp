#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // brute force O(n)
    // vector<vector<int>> merge(vector<vector<int>> &intervals)
    // {
    //     // vector<vector<int>> result;
    //     int start = 0, end = 0, it = 0;
    //     sort(intervals.begin(),intervals.end());
    //     while (it < intervals.size())
    //     {
    //         if (it < intervals.size() - 1)
    //         {
    //             if (intervals[it][0] <= intervals[it + 1][0] && intervals[it][1] <= intervals[it + 1][1] && intervals[it][1] >= intervals[it + 1][0])
    //             {
    //                 start = intervals[it][0];
    //                 end = intervals[it + 1][1];
    //                 intervals.erase(intervals.begin() + it, intervals.begin() + it + 2);
    //                 intervals.insert(intervals.begin() + it, {start, end});
    //             }
    //             else if (intervals[it + 1][0] <= intervals[it][0] && intervals[it + 1][1] <= intervals[it][1] && intervals[it][0] <= intervals[it + 1][1])
    //             {
    //                 start = intervals[it + 1][0];
    //                 end = intervals[it][1];
    //                 intervals.erase(intervals.begin() + it, intervals.begin() + it + 2);
    //                 intervals.insert(intervals.begin() + it, {start, end});
    //             }
    //             else if (intervals[it][0] <= intervals[it + 1][0] && intervals[it + 1][1] <= intervals[it][1])
    //             {
    //                 start = intervals[it][0];
    //                 end = intervals[it][1];
    //                 intervals.erase(intervals.begin() + it, intervals.begin() + it + 2);
    //                 intervals.insert(intervals.begin() + it, {start, end});
    //             }
    //             else if (intervals[it + 1][0] <= intervals[it][0] && intervals[it][1] <= intervals[it + 1][1])
    //             {
    //                 start = intervals[it + 1][0];
    //                 end = intervals[it + 1][1];
    //                 intervals.erase(intervals.begin() + it, intervals.begin() + it + 2);
    //                 intervals.insert(intervals.begin() + it, {start, end});
    //             }
    //             else
    //             {
    //                 start = intervals[it][0];
    //                 end = intervals[it][1];
    //                 it++;
    //             }
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     return intervals;
    // }

    // better approach o(nlogn + 2n);
    // vector<vector<int>> merge(vector<vector<int>> &intervals)
    // {
    //     int start, end;
    //     vector<vector<int>> ans;
    //     sort(intervals.begin(), intervals.end());
    //     for (int i = 0; i < intervals.size(); i++)
    //     {
    //         start = intervals[i][0], end = intervals[i][1];
    //         if (!ans.empty() && end <= ans.back()[1])
    //         {
    //             continue;
    //         }
    //         for (int j = i + 1; j < intervals.size(); j++)
    //         {
    //             if (end >= intervals[j][0])
    //             {
    //                 end = max(end, intervals[j][1]);
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }
    //         ans.push_back({start, end});
    //     }
    //     return ans;
    // }

    // best solution O(NlogN + N)
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int start, end;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            if (ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 2; j++)
        {
            cin >> m;
            temp.push_back(m);
        }
        intervals[i] = temp;
    }
    Solution s;
    vector<vector<int>> result = s.merge(intervals);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}