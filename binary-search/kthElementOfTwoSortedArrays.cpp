#include "bits/stdc++.h"

using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int n = 0, m = 0;
    vector<int> nums3;
    while (n < a.size() && m < b.size())
    {
        if (a[n] <= b[m])
        {
            nums3.push_back(a[n]);
            n++;
        }
        else if (a[n] > b[m])
        {
            nums3.push_back(b[m]);
            m++;
        }
    }
    if (n < a.size())
    {
        for (int i = n; i < a.size(); i++)
        {
            nums3.push_back(a[i]);
        }
    }
    else if (m < b.size())
    {
        for (int i = m; i < b.size(); i++)
        {
            nums3.push_back(b[i]);
        }
    }
    return nums3[k-1];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int result = kthElement(a, b, k);
    cout << result;
    return 0;
}