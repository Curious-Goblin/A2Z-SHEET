#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    // O(2n)
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, max_count = 0;
        unordered_map<int,int> map;
        while(right < fruits.size()){
            map[fruits[right]]++;
            right++;
            while(map.size()>2){
                map[fruits[left]]--;
                if(map[fruits[left]]==0){
                    map.erase(fruits[left]);
                }
                left++;
            }
            max_count = max(max_count, right-left);
        }
        return max_count;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> fruits(n);
    for(int i=0;i<n;i++){
        cin>>fruits[i];
    }
    Solution s;
    cout<<s.totalFruit(fruits);
    return 0;
}