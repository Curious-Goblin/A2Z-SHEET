#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void helper(vector<int> &arr, vector<int> &result, int &sum, int index){
        if(index == arr.size()){
            result.push_back(sum);
            return;
        }
        sum += arr[index];
        helper(arr, result, sum, index+1);
        sum -= arr[index];
        helper(arr, result, sum, index+1);
    }

    // O(2^n) recursion stack O(n)
    vector<int> subsetSums(vector<int> &arr){
        int sum = 0;
        vector<int> result;
        helper(arr, result, sum, 0);
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
    vector<int> result = s.subsetSums(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}