#include "bits/stdc++.h"

using namespace std;

class Solution {
    public:
    // o(2n)
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, length = 0;
        while(right < nums.size()){
            if(nums[right]==0 && k > 0){
                k--;
                right++;
            }
            else if(nums[right]==1){
                right++;
            }
            else{
                length = max(length, right - left);
                while(k==0){
                    if(nums[left]==0){
                        k++;
                    }
                    left++;
                }
            }
            length = max(length, right - left);
        }
        return length;
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
    cout<<s.longestOnes(nums,k);
    return 0;
}