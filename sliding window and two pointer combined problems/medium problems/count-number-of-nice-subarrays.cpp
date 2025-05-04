#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    // O(n)
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, odd_count = 0;
        unordered_map<int,int> map;
        map[0]=1;
        for(right = 0; right < nums.size(); ++right){
            if(nums[right] % 2 != 0){
                odd_count++;
            }
            auto it = map.find(odd_count - k);
            if(it != map.end()){
                count += it->second;
            }
            map[odd_count]++;
        }
        return count;
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
    cout<<s.numberOfSubarrays(nums,k);
    return 0;
}