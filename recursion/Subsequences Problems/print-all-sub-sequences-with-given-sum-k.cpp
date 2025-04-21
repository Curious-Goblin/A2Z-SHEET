#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution{
    public:
    // O(2^n) recursive call stack space is O(n)
    void helper(vector<int> &nums, vector<int> &path, vector<vector<int>> &result, int &sum, int index, int k){
        if(index == nums.size()){
            if(sum == k){
                result.push_back(path);
            }
            return;
        }
        path.push_back(nums[index]);
        sum += nums[index];
        helper(nums, path, result, sum, index+1, k);
        path.pop_back();
        sum -= nums[index];
        helper(nums, path, result, sum, index+1, k);
    }
    vector<vector<int>> sequencesWithSumK(vector<int> &nums, int k){
        int index = 0;
        int sum = 0;
        vector<int> path;
        vector<vector<int>> result;
        helper(nums, path, result, sum, index, k);
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
    vector<vector<int>> result = s.sequencesWithSumK(nums, k);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}