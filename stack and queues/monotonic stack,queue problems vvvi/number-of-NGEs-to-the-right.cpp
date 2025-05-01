#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:

    // time complextiy is O(q*n)
    // vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
    //     int count = 0;
    //     vector<int> result;
    //     for(int i=0;i<queries;i++){
    //         count = 0;
    //         for(int j = n-1;j>=indices[i] + 1;j--){
    //             if(arr[j] > arr[indices[i]]){
    //                 count++;
    //             }
    //         }
    //         result.push_back(count);
    //     }
    //     return result;
    // }

    // O(nlogn + qlogq)
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> result(queries);
        vector<pair<int,int>> queriesWithIndex;

        for(int i=0;i<queries;i++){
            queriesWithIndex.push_back({indices[i],i});
        }

        // qlogq;
        sort(queriesWithIndex.rbegin(), queriesWithIndex.rend());

        multiset<int> suffixElement;
        int j = n-1;

        for(auto& [idx, originalIndex] : queriesWithIndex){
            // o(n)
            while(j>idx){
                suffixElement.insert(arr[j]);
                j--;
            }
            
            // O(logn)
            auto it = suffixElement.upper_bound(arr[idx]);
            int count = distance(it, suffixElement.end());
            result[originalIndex] = count;
        }
        return result;
    }
};

int main(){
    int n, queries;
    cin>>n>>queries;
    vector<int> arr(n),indices(queries);
    for(int i=0;i<queries;i++){
        cin>>indices[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution s;
    vector<int> result = s.count_NGE(n,arr,queries,indices);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}