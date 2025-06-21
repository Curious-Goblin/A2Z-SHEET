#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] != 100000000 && dist[k][j] != 100000000){
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    Solution sol;
    sol.floydWarshall(dist);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}