#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dataTypeSize(string str) {
        if(str=="Integer"){
            return 4;
        }
        else if(str=="Character"){
            return 1;
        }
        else if(str=="Long"){
            return 8;
        }
        else if(str=="Float"){
            return 4;
        }
        else return 8;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}
