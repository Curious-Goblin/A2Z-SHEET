#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            vector<string> vec;
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != ' ') {
                    temp += s[i];
                } else if (s[i] == ' ') {
                    if (temp != "") {
                        vec.push_back(temp);
                        temp = "";
                    }
                }
            }
            if (temp != "") {
                vec.push_back(temp);
                temp = "";
            }
            for (int i = vec.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    temp += vec[i];
                    // temp += '"';
                } else if (i == vec.size() - 1) {
                    // temp += '"';
                    temp += vec[i];
                    temp += ' ';
                } else {
                    temp += vec[i];
                    temp += ' ';
                }
            }
            return temp;
        }
    };


int main(){
    string s;
    getline(cin, s);
    Solution solve;
    string result = solve.reverseWords(s);
    cout << result;
    return 0;
}