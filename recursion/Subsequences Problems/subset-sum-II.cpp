#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:

    // here the base case is automatically handled by the loop, here we need to add the path at
    // each level, earlier we use to add path only when we had decided for every element but
    // here we need to add path at every recursion level to include each unique subset.
    // O(n*2^n)
    void helper(vector<int> &nums, vector<int> &path, vector<vector<int>> &result, int index){
        result.push_back(path);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            helper(nums, path, result, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums){
        vector<int> path;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        helper(nums, path, result, 0);
        return result;
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
    vector<vector<int>> result = s.subsetsWithDup(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}