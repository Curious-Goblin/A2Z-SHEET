#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int,int> freq;
        for(int &i: hand){
            freq[i]++;
        }
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int card = it->first;
            int need = it->second;
            if (need == 0) continue;

            for (int i = 0; i < groupSize; ++i) {
                int nextCard = card + i;
                if (freq[nextCard] < need) return false;
                freq[nextCard] -= need;
            }
        }
        return true;
    }
};

int main(){
    int n;
    int size;
    cin>>n;
    cin>>size;
    vector<int> nums(n);
    for(int i = 0; i < n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.isNStraightHand(nums, size);
    return 0;
}