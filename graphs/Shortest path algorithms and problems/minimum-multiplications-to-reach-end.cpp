#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        vector<int> dist(MOD, INT_MAX);
        dist[start] = 0;
        queue<int> qu;
        qu.push(start);
        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();

            if(curr == end){
                return dist[end];
            }

            for(auto &num:arr){
                int next = (1LL * num * curr)%MOD;
                if(dist[next] == INT_MAX){
                    dist[next] = dist[curr] + 1;
                    qu.push(next);
                }
            }
        }
        return -1;
    }
};

int main(){
    int n, start, end;
    cin>>n>>start>>end;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    cout<<sol.minimumMultiplications(arr, start, end);
    return 0;
}