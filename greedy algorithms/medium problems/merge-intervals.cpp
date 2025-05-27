#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();
        for(int i=0;i<n-1;i++){
            if(intervals[i][1] < intervals[i+1][0]){
                result.push_back({intervals[i][0], intervals[i][1]});
            }
            else if(intervals[i][0] <= intervals[i+1][1]){
                intervals[i+1][0] = min(intervals[i][0], intervals[i+1][0]);
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
        }
        result.push_back({intervals[n-1][0], intervals[n-1][1]});
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0];
        cin>>intervals[i][1];
    }
    Solution s;
    vector<vector<int>> result = s.merge(intervals);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}