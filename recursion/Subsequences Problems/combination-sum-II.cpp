#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution{
    public:

    void helper(vector<int> &candidates, vector<int> &path, vector<vector<int>> &result, int index, int target){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(target < 0 || index == candidates.size()){
            return;
        }
        for(int i=index;i<candidates.size();++i){
            if(i > index && candidates[i]==candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            helper(candidates, path, result, i+1, target - candidates[i]);
            path.pop_back();
        }
    }
    // O(NlogN + M*R) M = no of unique combinations , R = average length of each combination.
    // space = O(n+m*r)
    vector<vector<int>> combinationSum2(vector<int> &candidates, int &target){
        int index = 0;
        vector<int> path;
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
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
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}