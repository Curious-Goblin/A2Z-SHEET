#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> monotonic;
        bool destroyed = false;
        for(int &i:asteroids){
            destroyed = false;
            while(!monotonic.empty() && i < 0 && monotonic.top() > 0){
                if(monotonic.top() > abs(i)){
                    destroyed = true;
                    break;
                }
                else if(monotonic.top() == abs(i)){
                    monotonic.pop();
                    destroyed = true;
                    break;
                }
                else{
                    monotonic.pop();
                }
            }
            if(!destroyed){
                monotonic.push(i);
            }
        }
        vector<int> result;
        while(!monotonic.empty()){
            result.push_back(monotonic.top());
            monotonic.pop();
        }
        reverse(result.begin(), result.end());
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
    vector<int> result = s.asteroidCollision(nums);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}