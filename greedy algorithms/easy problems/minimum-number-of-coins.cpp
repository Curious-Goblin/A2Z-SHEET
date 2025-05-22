#include "bits/stdc++.h"

using namespace std;

// class Solution {
//   public:
// O(klogk + M) k is the number of unique coins/notes and m is the number of total coins/notes
//     vector<int> minPartition(int N) {
//         vector<int> coins = {1, 2, 5};
//         vector<int> notes = {10, 20, 50, 100, 200, 500, 2000};
//         int change = N%10;
//         unordered_map<int,int> result;
//         N = N - change;
//         if(change!=0){
//             for(int i = coins.size()-1;i>=0 && change > 0;i--){
//                 if(change >= coins[i]){
//                     result[coins[i]] = change/coins[i];
//                     change -= coins[i]*(change/coins[i]);
//                 }
//             }
//         }
//         if(N!=0){
//             for(int i = notes.size()-1; i>=0 && N > 0; i--){
//                 if(N >= notes[i]){
//                     result[notes[i]] = N/notes[i];
//                     N -= notes[i]*(N/notes[i]);
//                 }
//             }
//         }
//         priority_queue<int> pq;
//         for(auto &it:result){
//             for(int i=0;i<it.second;i++){
//                 pq.push(it.first);
//             }
//         }
//         vector<int> result1;
//         while(!pq.empty()){
//             result1.push_back(pq.top());
//             pq.pop();
//         }
//         return result1;
//     }
// };

class Solution {
  public:
    vector<int> minPartition(int N) {
        vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> result;
        
        for (int denom : denominations) {
            while (N >= denom) {
                result.push_back(denom);
                N -= denom;
            }
        }
        return result;
    }
};


int main(){
    int n;
    cin>>n;
    Solution s;
    vector<int> result = s.minPartition(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}