#include "iostream"
#include "vector"
#include "numeric"
#include "bits/stdc++.h"

using namespace std;

int findPages(vector<int>& arr, int n, int m) {
    if(m>n){
        return -1;
    }
    int high = *max_element(arr.begin(),arr.end()), sum = accumulate(arr.begin(),arr.end(),0), min=0;
    for(int i=high;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(min<i){
                min=min+arr[j];
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result = findPages(arr,n,m);
    cout<<result;
    return 0;
}