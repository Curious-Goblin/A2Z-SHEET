#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<int> nextSmallerElementLeft(vector<int> &nums)
    {
        vector<int> result;
        stack<int> monotonic;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!monotonic.empty() && nums[monotonic.top()] > nums[i])
            {
                monotonic.pop();
            }
            result.push_back(monotonic.empty() ? -1 : monotonic.top());
            monotonic.push(i);
        }
        return result;
    }
    vector<int> nextSmallerElementRight(vector<int> &nums)
    {
        vector<int> result;
        stack<int> monotonic;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            while (!monotonic.empty() && nums[monotonic.top()] >= nums[i])
            {
                monotonic.pop();
            }
            result.push_back(monotonic.empty() ? -1 : monotonic.top());
            monotonic.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // O(3n)
    int64_t sumSubarrayMins(vector<int>& arr) {
        vector<int> left = nextSmallerElementLeft(arr);
        vector<int> right = nextSmallerElementRight(arr);
        int64_t minimum = 0;
        int leftCount = 0, rightCount = 0;
        for(int i=0;i<arr.size();i++){
            leftCount = (left[i] == -1) ? i + 1 : i-left[i];
            rightCount = (right[i] == -1) ? arr.size()-i : right[i] - i; 
            minimum  += 1LL * arr[i] * leftCount * rightCount;
            leftCount = 0, rightCount = 0;
        }
        return minimum;
    }


    vector<int> nextGreaterElementRight(vector<int> &nums)
    {
        vector<int> result;
        stack<int> monotonic;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!monotonic.empty() && nums[monotonic.top()] < nums[i])
            {
                monotonic.pop();
            }
            result.push_back(monotonic.empty()?-1:monotonic.top());
            monotonic.push(i);
        }
        reverse(result.begin(),result.end());
        return result;
    }
    vector<int> nextGreaterElementLeft(vector<int> &nums)
    {
        vector<int> result;
        stack<int> monotonic;
        for (int i=0;i<nums.size();i++)
        {
            while (!monotonic.empty() && nums[monotonic.top()] <= nums[i])
            {
                monotonic.pop();
            }  
            result.push_back(monotonic.empty()?-1:monotonic.top());
            monotonic.push(i);
        }
        return result;
    }
    
    // O(3n)
    int64_t sumSubarrayMaxs(vector<int>& nums){
        vector<int> left = nextGreaterElementLeft(nums);
        vector<int> right = nextGreaterElementRight(nums);
        int64_t maximum = 0;
        int leftCount = 0, rightCount = 0;
        for(int i=0;i<nums.size();i++){
            leftCount = (left[i] == -1) ? i + 1 : i-left[i];
            rightCount = (right[i] == -1) ? nums.size()-i : right[i] - i; 
            maximum  += 1LL * nums[i] * leftCount * rightCount;
            leftCount = 0, rightCount = 0;
        }
        return maximum;
    }

    // o(6n)
    int64_t subArrayRanges(vector<int>& nums) {
        int64_t sumMin = sumSubarrayMins(nums);
        int64_t sumMax = sumSubarrayMaxs(nums);
        return sumMax - sumMin;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    int64_t result = s.subArrayRanges(nums);
    cout<<result;
    return 0;
}