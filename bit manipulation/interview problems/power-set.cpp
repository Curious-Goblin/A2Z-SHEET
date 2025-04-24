#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution{
    public:
    vector<vector<int>> subsets(vector<int> &nums){
        int n = 1<<nums.size();
        n = n-1;
        vector<vector<int>> result;
        for(int i=0;i<=n;i++){
            vector<int> temp;
            bitset<10> binary(i);
            for(int j=0;j<nums.size();j++){
                if(binary[j]==1){
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
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
}