#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // O(n)
    // This solution uses a prefix sum and a hash map to count how many times a specific sum
    //  has occurred. By checking if `(current_sum - goal)` exists in the map, it finds how
    //  many subarrays ending at the current index sum to the target. Initializing `hash[0] = 1`
    //  handles subarrays that start from the beginning.

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> hash;
        hash[0]=1;
        int current_sum = 0, left = 0, right = 0, count = 0;
        for(right = 0; right < nums.size(); ++right)
        {
            current_sum += nums[right];
            auto it = hash.find(current_sum - goal);
            if(it != hash.end()){
                count += it->second;
            } 
            hash[current_sum]++;
        }
        return count;
    }
};

int main(){
    int n, goal;
    cin>>n>>goal;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.numSubarraysWithSum(nums, goal);
    return 0;
}