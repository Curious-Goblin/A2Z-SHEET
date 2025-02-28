#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<int> lcmAndGcd(int a, int b)
    {
        vector<int> result;
        int num1 = (a > b) ? a : b;
        int num2 = a < b ? a : b;
        int temp = 0;
        while (num2 != 0)
        {
            temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        result.push_back(num1);
        int lcm = (a * b) / result[0];
        result.push_back(lcm);
        temp = result[0];
        result[0] = result[1];
        result[1] = temp;
        return result;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Solution solve;
    vector<int> result = solve.lcmAndGcd(a,b);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}