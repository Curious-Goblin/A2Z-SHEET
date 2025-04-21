#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution{
    public:
    void helper(vector<int> &nums, vector<int> &path, int &count, int index, int k){
        if(index == nums.size()){
            int sum = accumulate(path.begin(),path.end(),0);
            if(sum == k){
                count++;
            }
            return;
        }
        path.push_back(nums[index]);
        helper(nums, path, count, index+1, k);
        path.pop_back();
        helper(nums, path, count, index+1, k);
    }
    int sequencesWithSumK(vector<int> &nums, int k){
        int index = 0;
        int count = 0;
        vector<int> path;
        helper(nums, path, count, index, k);
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
    int result = s.sequencesWithSumK(nums, k);
    cout<<result;
    return 0;
}