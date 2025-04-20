#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    // O(NlogN)
    // This code finds the maximum frequency of any number in the array after performing
    // at most `k` increments. It uses a **sliding window** on the sorted array to
    // maintain the largest subarray where all elements can be made equal to `nums[right]`
    // within `k` operations.
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            long long total = 0;
            int result =0, left =0;
            for(int right = 0;right<nums.size();right++){
                total += nums[right];
                while((long long)nums[right]*(right - left + 1) - total > k){
                    total -= nums[left];
                    left++;
                }
                result = max(result,right-left+1);
            }
            return result;
        }
    };

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    int result = s.maxFrequency(nums,k);
    cout<<result;
    return 0;
}