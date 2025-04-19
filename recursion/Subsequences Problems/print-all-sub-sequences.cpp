#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:

    // time and space complexity = O(n * 2^n)
    void helper(vector<int> &path, vector<vector<int>> &result, int index, vector<int> &nums){
        if(index == nums.size()){
            result.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        helper(path,result,index+1,nums);
        path.pop_back();
        helper(path,result,index+1,nums);
    }
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> result;
        vector<int> path;
        helper(path,result,0,nums);
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
    vector<vector<int>> result = s.subsets(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}