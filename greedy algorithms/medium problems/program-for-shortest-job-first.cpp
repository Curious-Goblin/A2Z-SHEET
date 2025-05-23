#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
//   O(NlogN)
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        vector<int> waiting_time = {0};
        for(int i=1;i<bt.size();i++){
            waiting_time.push_back(waiting_time[waiting_time.size()-1] + bt[i-1]);
        }
        int result = 0;
        for(int i=0;i<waiting_time.size();i++){
            result += waiting_time[i];
        }
        result /= waiting_time.size();
        return (long long)result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> bt(n);
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    Solution s;
    cout<<s.solve(bt);
    return 0;
}