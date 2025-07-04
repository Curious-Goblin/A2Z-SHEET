#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool spaceOptimized(vector<int>& arr, int& sum){
        int n = arr.size();
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(sum >= arr[0]) prev[arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                curr[target] = prev[target] || (target >= arr[i] && prev[target-arr[i]]);
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        if(total % 2 != 0) return false;
        else{
            total /= 2;
            return spaceOptimized(nums, total);
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    cout<<sol.canPartition(arr);
    return 0;
}