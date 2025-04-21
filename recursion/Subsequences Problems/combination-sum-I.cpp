#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution{
    public:
    // time complexity is O(n^(T/minVal)) 
    // n = number of candidates, 
    // T = target, 
    // minVal = minimum value candidate, 
    // it is because at each level we have n options and at the worst case recursion would 
    // go deep down to T/minVal levels therefore the time complexity.
    // space complexity is O(combinations * T)
    void helper(vector<int> &candidates, vector<int> &path, vector<vector<int>> &result, int index, int target){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(target < 0 || index == candidates.size()){
            return;
        }
        path.push_back(candidates[index]);
        helper(candidates, path, result, index, target - candidates[index]);
        path.pop_back();
        helper(candidates, path, result, index+1, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int &target){
        int index = 0;
        vector<int> path;
        vector<vector<int>> result;
        helper(candidates, path, result, index, target);
        return result;
    }
};

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> candidates(n);
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }
    Solution s;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}