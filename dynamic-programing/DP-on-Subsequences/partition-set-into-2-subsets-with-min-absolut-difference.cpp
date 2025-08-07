#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
// for arr with non negative values
    // vector<bool> spaceOptimized(vector<int>& arr, int& sum){
    //     int n = arr.size();
    //     vector<bool> prev(sum+1,0), curr(sum+1,0);
    //     prev[0]=curr[0]=true;
    //     if(sum >= arr[0]) prev[arr[0]] = true;
    //     for(int i=1;i<n;i++){
    //         for(int target=1;target<=sum;target++){
    //             curr[target] = prev[target] || (target >= arr[i] && prev[target-arr[i]]);
    //         }
    //         prev = curr;
    //     }
    //     return prev;
    // }
    // int minimumDifference(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum =0;
    //     for(int i=0;i<n;i++){
    //         sum += nums[i];
    //     }
    //     vector<bool> result = spaceOptimized(nums, sum);
    //     int minDiff = 1e9;
    //     for(int i=0;i<result.size();i++){
    //         if(result[i]){
    //             minDiff = min(minDiff, abs(sum - (2*i)));
    //         } 
    //     }
    //     return minDiff;
    // }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.minimumDifference(nums);
    return 0;
}