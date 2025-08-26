#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if(wordset.count(endWord) == 0) return {};
        vector<vector<string>> result;
        vector<string> usedonlevel;
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        usedonlevel.push_back(beginWord);
        while(!q.empty()){
            auto list = q.front();
            q.pop();

            if(list.size() > level){
                level++;
                for(auto it:usedonlevel){
                    wordset.erase(it);
                }
                usedonlevel.clear();
            } 

            string word = list.back();

            if(word == endWord){
                if(result.size()==0){
                    result.push_back(list);
                }
                else if(result[0].size() == list.size()){
                    result.push_back(list);
                }
                else{
                    break;
                }
            }

            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char c = 'a';c<='z';c++){
                    if(c==original) continue;
                    word[i] = c;
                    if(wordset.count(word)){
                        list.push_back(word);
                        q.push(list);
                        list.pop_back();
                        usedonlevel.push_back(word);
                    }
                }
                word[i] = original;
            }
        }
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    string beginWord, endWord;
    cin>>beginWord>>endWord;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    Solution sol;
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, words);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}