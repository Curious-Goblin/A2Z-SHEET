#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    // O(N*2 * M) m = unique characters
     
    int beautySum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            map<char, int> freq;
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j]]++;
                int least_frequent = INT32_MAX;
                int most_frequent = INT32_MIN;
                for (auto it : freq)
                {
                    least_frequent = min(least_frequent, it.second);
                    most_frequent = max(most_frequent, it.second);
                }
                ans += most_frequent - least_frequent;
            }
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    int result = solve.beautySum(s);
    cout << result;
    return 0;
}