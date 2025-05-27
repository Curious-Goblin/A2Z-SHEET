#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
// We sort the intervals by their end times to always choose the interval that finishes earliest.
// Then we iterate through the list and count overlaps — if the current interval starts before the 
// last one ends, we remove it.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1]<b[1];
        });
        int n = intervals.size(),count=0, prevEnd = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] < prevEnd){
                count++;
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        return count;
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
    cout<<s.eraseOverlapIntervals(intervals);
    return 0;
}