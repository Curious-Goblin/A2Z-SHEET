#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // Nlogn
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        priority_queue<tuple<int,int,int>> maxHeap;

        set<pair<int,int>> visited;

        // logn here n is the number of elements currently present in the heap
        maxHeap.push(make_tuple(A[0]+B[0], 0, 0));
        visited.insert({0,0});

        vector<int> result;

        // klogn
        while(K-- && !maxHeap.empty()){
            auto [sum, i, j] = maxHeap.top();
            maxHeap.pop();
            result.push_back(sum);

            if(i+1 < N && visited.find({i+1,j})==visited.end()){
                maxHeap.push(make_tuple(A[i+1]+B[j],i+1,j));
                visited.insert({i+1,j});
            }
            if(j+1 < N && visited.find({i,j+1})==visited.end()){
                maxHeap.push(make_tuple(A[i]+B[j+1],i,j+1));
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> numsA(n), numsB(n);
    for(int i=0;i<n;i++){
        cin>>numsA[i];
    }
    for(int i=0;i<n;i++){
        cin>>numsB[i];
    }
    Solution s;
    vector<int> result = s.maxCombinations(n,k,numsA,numsB);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}