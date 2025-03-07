#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    bool isPossible(int a, int b)
    {
        if (a == 2 && b == 2)
            return false;
        return (a == 2 || b == 2);
    }
};

int main()
{
    return 0;
}