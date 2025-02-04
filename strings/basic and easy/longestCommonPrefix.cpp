#include "bits/stdc++.h"

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string temp = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] != strs[i][j])
            {
                temp = temp.substr(0, j);
            }
        }
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    string result = longestCommonPrefix(strs);
    cout << result;
    return 0;
}