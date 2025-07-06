#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void tabulation(const string& text1, const string& text2, vector<vector<int>>& dp) {
        int s1 = text1.size(), s2 = text2.size();
        for (int i = 0; i <= s1; i++) {
            for (int j = 0; j <= s2; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        tabulation(str1, str2, dp);
        int i = n, j = m;
        string ans;
        ans.reserve(n + m);

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
            }
            else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) ans.push_back(str1[--i]);
        while (j > 0) ans.push_back(str2[--j]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.shortestCommonSupersequence(s1, s2) << endl;
    return 0;
}
