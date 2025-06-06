#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, farthest = 0, end = 0;
        for(int i = 0; i < nums.size()-1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == end){
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.jump(nums);
    return 0;
}