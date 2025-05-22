#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
// here we are traversing backwards and at every iteration we are looking that is it possible from the 
// current index to reach at the goal and if yes we shift the goal to this index and so on. so if goal
// at last is 0 then the answer is true;
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int goal = nums.size()-1;
        for(int i = nums.size()-2;i>=0;i--){
            if(i+nums[i]>=goal){
                goal = i;
            }
        }
        if(goal == 0){
            return true;
        }
        return false;
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
    cout<<s.canJump(nums);
    return 0;
}