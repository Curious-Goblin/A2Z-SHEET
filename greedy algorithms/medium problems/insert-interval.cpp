#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0, n = intervals.size();
        
        while(i<n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++
        }
        result.push_back(newInterval);

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n, vector<int>(2));
    vector<int> newInterval(2);
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>intervals[i][j];
        }
    }
    for(int i=0;i<2;i++){
        cin>>newInterval[i];
    }
    Solution s;
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<2;j++){
            cout<<result[i][j]<<" "
        }
        cout<<endl;
    }
    return 0;
}