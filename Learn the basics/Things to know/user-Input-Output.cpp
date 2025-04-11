#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class AutoCompleteSystem
{
public:
    string subSentence = "";
    multimap<int, string, greater<int>> history;

    AutoCompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        for (int i = 0; i < sentences.size(); i++)
        {
            history.insert({times[i], sentences[i]});
        }
    }

    vector<string> input(char c)
    {
        if (c == '#')
        {
            int existingFreq = 0;
            for (auto it = history.begin(); it != history.end();)
            {
                if (it->second == subSentence)
                {
                    existingFreq = it->first;
                    it = history.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            history.insert({existingFreq + 1, subSentence});
            subSentence = "";
            return {};
        }

        subSentence += c;
        vector<pair<int, string>> candidates;

        for (auto &entry : history)
        {
            if (entry.second.substr(0, subSentence.size()) == subSentence)
            {
                candidates.emplace_back(entry.first, entry.second);
            }
        }

        sort(candidates.begin(), candidates.end(), [](auto &a, auto &b)
             {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second; });

        vector<string> result;
        for (int i = 0; i < min(3, (int)candidates.size()); ++i)
        {
            result.push_back(candidates[i].second);
        }

        return result;
    }
};
