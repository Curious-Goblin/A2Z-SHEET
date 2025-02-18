#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    double switchCase(int choice, vector<double> &arr)
    {
        switch (choice)
        {
        case 1:
            return M_PI * arr[0] * arr[0];
        case 2:
            return arr[0] * arr[1];
        }
    }
};

int main()
{
    int n, choice;
    cin >> n >> choice;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}