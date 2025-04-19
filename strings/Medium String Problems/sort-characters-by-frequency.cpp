#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // o(n + k + klogk)
    // string frequencySort(string s)
    // {
    //     map<char, int> frequencyMap;
    //     // o(n)
    //     for (size_t i = 0; i < s.size(); i++)
    //     {
    //         frequencyMap[s[i]]++;
    //     }

    //     // o(k) k = number of unique characters
    //     vector<pair<char, int>> sortedFrequency(frequencyMap.begin(), frequencyMap.end());

    //     // lambda comparator o(klogk)
    //     sort(sortedFrequency.begin(), sortedFrequency.end(),
    //          [](const pair<char, int> &a, const pair<char, int> &b)
    //          { return a.second > b.second; });

    //     string result = "";
    //     for (int i = 0; i < sortedFrequency.size(); i++)
    //     {
    //         for (int j = 0; j < sortedFrequency[i].second; j++)
    //         {
    //             result += sortedFrequency[i].first;
    //         }
    //     }
    //     return result;
    // }

    // O(n+K+n)
    string frequencySort(string s)
    {
        map<char, int> frequencyMap;
        // o(n)
        for (size_t i = 0; i < s.size(); i++)
        {
            frequencyMap[s[i]]++;
        }

        // o(k) k = number of unique characters
        vector<vector<char>> sortedFrequency(s.size() + 1);

        for (auto &it : frequencyMap)
        {
            sortedFrequency[it.second].push_back(it.first);
        }
        string result = "";

        // O(n)
        for(int i=sortedFrequency.size()-1;i>=0;i--){
            for(int j=0;j<sortedFrequency[i].size();j++){
                for(int k=0;k<i;k++){
                    result+=sortedFrequency[i][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    string result = solve.frequencySort(s);
    cout << result;
    return 0;
}