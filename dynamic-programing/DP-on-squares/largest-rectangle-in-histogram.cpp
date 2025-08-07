#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> leftsmaller(vector<int> &heights){
        vector<int> result(heights.size(),0);
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()){
                if(heights[st.top()] >= heights[i]){
                    st.pop();
                }
                else{
                    result[i] = st.top() + 1;
                    st.push(i);
                    break;
                }
            }
            if(st.empty()) {
                result[i] = 0;
                st.push(i);
            }
        }
        return result;
    }
    vector<int> rightsmaller(vector<int> &heights){
        vector<int> result(heights.size(),0);
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty()){
                if(heights[st.top()] >= heights[i]){
                    st.pop();
                }
                else{
                    result[i] = st.top() - 1;
                    st.push(i);
                    break;
                }
            }
            if(st.empty()) {
                result[i] = heights.size()-1;
                st.push(i);
            }
        }
        return result;
    }
    // int largestRectangleArea(vector<int>& heights) {
    //     int area=0, maxArea = 0;
    //     vector<int> left = leftsmaller(heights);
    //     vector<int> right = rightsmaller(heights);
    //     for(int i=0;i<heights.size();i++){
    //         area = (right[i] - left[i] + 1) * heights[i];
    //         maxArea = max(maxArea, area);
    //     }
    //     return maxArea;
    // }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size(), maxArea=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width=0;
                if(st.empty()) width = i;
                else width = i - st.top() - 1; 
                maxArea = max(maxArea, width*height);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    Solution sol;
    cout<<sol.largestRectangleArea(heights);
    return 0;
}