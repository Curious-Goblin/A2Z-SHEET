#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        int pageFaults = C;
        multimap<int, int> memory;
        for (int i = 0; i < C; i++)
        {
            memory.insert({pages[i], i});
        }
        int i = 0, j = C;
        while (j < N)
        {
            if (pages[i] != pages[j])
            {
                if (memory.find(pages[j]) == memory.end())
                {
                    pageFaults++;
                    memory.erase(pages[i]);
                    memory.insert({pages[j],j});
                }
            }
            i++, j++;
        }
        return pageFaults;
    }
};

int main()
{
    int n, c;
    cin >> n >> c;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    Solution solve;
    cout << solve.pageFaults(n, c, pages);
    return 0;
}