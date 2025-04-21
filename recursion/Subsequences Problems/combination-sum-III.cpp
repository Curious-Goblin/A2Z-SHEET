#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:

    // time and space complexity is O( C(9,k) * k)  we are choosing k numbers from 9 options.
    void helper(vector<int> &nums, vector<int> &path, vector<vector<int>> &result, int target, int size, int index){
        if(target==0 && size == 0){
            result.push_back(path);
            return;
        }
        if(target < 0 || index == nums.size()){
            return;
        }
        path.push_back(nums[index]);
        helper(nums, path, result, target-nums[index], size-1, index + 1);
        path.pop_back();
        helper(nums, path, result, target, size, index + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n){
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> path;
        vector<vector<int>> result;
        helper(nums, path, result, n, k, 0);
        return result;
    }
};

int main(){
    int k,n;
    cin>>k>>n;
    Solution s;
    vector<vector<int>> result = s.combinationSum3(k,n);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        if(i<result.size()-1){
            cout<<endl;
        }
    }
    return 0;
}