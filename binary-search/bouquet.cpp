#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int minDays(vector<int> &bloomDay, int m, int k)
{
    int low, high, counter, bouquet, mid;
    low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
    long long unsigned int product = m * k;
    if (bloomDay.size() < product)
    {
        return -1;
    }
    while (low <= high)
    {
        mid = (low + high) / 2;
        counter = 0, bouquet = 0;
        for (int j = 0; j < bloomDay.size(); j++)
        {
            if (bloomDay[j] <= mid)
            {
                counter++;
            }
            else if (bloomDay[j] > mid)
            {
                bouquet += counter / k;
                counter = 0;
            }
        }
        bouquet += counter / k;
        if (bouquet >= m)
        {
            high = mid - 1;
        }
        else if (bouquet < m)
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> bloomDay(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }
    int result = minDays(bloomDay, m, k);
    cout << result;
    return 0;
}