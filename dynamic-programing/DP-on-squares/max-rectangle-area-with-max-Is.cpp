#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int size = matrix[0].size();
        vector<int> histo(size,0);
        int maxA=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == '1'){
                    histo[j] += 1;
                }
                else histo[j] = 0;
            }
            maxA = max(maxA, largestRectangleArea(histo));
        }
        return maxA;
    }
};

int main(){
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<char>> matrix(rows, vector<char>(columns));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>matrix[i][j];
        }
    }
    Solution sol;
    cout<<sol.maximalRectangle(matrix);
    return 0;
}