#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if(wordset.count(endWord)==0) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto w = q.front();
            q.pop();

            if(w.first == endWord) return w.second;

            for(int i=0;i<w.first.size();i++){
                string temp = w.first;
                for(char c = 'a'; c <= 'z';c++){
                    temp[i] = c;
                    if(wordset.count(temp)){
                        q.push({temp, w.second + 1});
                        wordset.erase(temp); // visited
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    int n;
    cin>>n;
    string beginWord, endWord;
    cin>>beginWord>>endWord;
    vector<string> wordList(n);
    for(int i=0;i<n;i++){
        cin>>wordList[i];
    }
    Solution sol;
    cout<<sol.ladderLength(beginWord, endWord, wordList);
}