#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adMatrix(n, vector<int>(n,100000000));
        for(int i=0;i<edges.size();i++){
            adMatrix[edges[i][0]][edges[i][1]] = edges[i][2];
            adMatrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adMatrix[i][k] != 100000000 && adMatrix[k][j] != 100000000){
                        adMatrix[i][j] = min(adMatrix[i][j], adMatrix[i][k]+adMatrix[k][j]);
                    }
                }
            }
        }

        int minReachable = n+1;
        int city = -1;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(i!=j && adMatrix[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <= minReachable){
                minReachable = count;
                city = i;
            }
        }
        return city;
    }
};

int main(){
    int n, e, distanceThreshold;
    cin>>n>>e>>distanceThreshold;
    vector<vector<int>> edges(e,vector<int>(3));
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    Solution sol;
    cout<<sol.findTheCity(n, edges, distanceThreshold);
    return 0;
}