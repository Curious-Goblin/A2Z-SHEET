#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // O(n)
    int maxScore(vector<int> &cardPoints, int k){
        if(k == cardPoints.size()){
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        int size = cardPoints.size() - k;
        int left = 0, right = 0, sum = 0, min_sum = INT_MAX, total_sum = 0;
        for(; right < cardPoints.size(); right++){
            total_sum += cardPoints[right];
            sum += cardPoints[right];
            if(right - left + 1 == size){
                min_sum = min(sum, min_sum);
                sum -= cardPoints[left];
                left++;
            }
        }
        return total_sum - min_sum;
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.maxScore(nums,k);
    return 0;
}