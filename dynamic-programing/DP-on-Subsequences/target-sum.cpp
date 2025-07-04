#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(vector<int>& nums, int &target, int index, int sum){
        if(index < 0){
            return sum == target ? 1 : 0;
        }
        int skip = recursion(nums, target, index-1, sum+nums[index]);
        int take = recursion(nums, target, index-1, sum-nums[index]);
        return skip + take;
    }
    int spaceOptimized(vector<int>& arr, int& sum){
        int n = arr.size();
        vector<int> prev(sum+1,0), curr(sum+1,0);
        prev[0]=curr[0]=1;
        if(sum >= arr[0]) prev[arr[0]] += 1;
        if(arr[0]==0) prev[0] = 2;
        for(int i=1;i<n;i++){
            curr[0] = (arr[i] == 0) ? (2 * prev[0]) : prev[0];
            for(int target=1;target<=sum;target++){
                curr[target] = prev[target];
                if(target >= arr[i]){
                    curr[target] += prev[target - arr[i]];
                }
            }
            prev = curr;
        }
        return prev[sum];
    }
    int countPartitions(vector<int>& arr, int d) {
        int total = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            total += arr[i];
        }
        int target = (total - d)/2;
        if(target < 0 || (total - d) % 2 != 0) return 0;
        return spaceOptimized(arr, target);        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // return recursion(nums, target, n-1, 0);
        return countPartitions(nums, target);
    }
};

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.findTargetSumWays(nums, target);
    return 0;
}