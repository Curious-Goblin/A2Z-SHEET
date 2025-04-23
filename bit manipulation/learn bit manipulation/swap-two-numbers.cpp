#include <iostream>

using namespace std;

class Solution{
    public:
    pair<int,int> get(int a, int b){
        a = a^b;
        b = b^a;
        a = a^b;
        return {a,b};
    }
};

int main(){
    int a, b;
    cin>>a>>b;
    Solution s;
    pair<int,int> result = s.get(a,b);
    cout<<result.first<<" "<<result.second;
}