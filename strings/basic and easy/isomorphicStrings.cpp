#include "bits/stdc++.h"

using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> map(256, -1);
    vector<int> map2(256, -1);

    for (int i = 0; i < s.size(); i++)
    {

        if (map[s[i]] != -1 && map[s[i]] != t[i])
            return false;
        if (map2[t[i]] != -1 && map2[t[i]] != s[i])
            return false;

        map[s[i]] = t[i];
        map2[t[i]] = s[i];
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    bool result = isIsomorphic(s, t);
    cout << result;
    return 0;
}