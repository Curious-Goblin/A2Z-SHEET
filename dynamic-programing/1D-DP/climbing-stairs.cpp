#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> ways;
    Solution()
    {
        ways = vector<int>(46, 0);
        ways[1] = 1, ways[2] = 2;
    }

    int climbStairs2(int n)
    {
        if (n <= 2)
        {
            return ways[n];
        }
        else if (ways[n] != 0)
        {
            return ways[n];
        }
        return ways[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    int climbStairs(int n){
        if(n <= 2){
            return n;
        }
        int prev = 1, prev1 = 2, curri = 0;
        for(int i=3;i<=n;i++){
            curri = prev + prev1;
            prev = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int result = s.climbStairs2(n);
    cout << result;
    return 0;
}