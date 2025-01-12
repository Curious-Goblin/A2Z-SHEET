#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end()), 
    high = accumulate(weights.begin(), weights.end(), 0), 
    mid, counter, weight;
    while (low <= high)
    {
        mid = (low + high) / 2;
        counter = 1, weight = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weight + weights[i] > mid)
            {
                counter += 1;
                weight = weights[i];
            }
            else
            {
                weight += weights[i];
            }
        }
        if (counter > days)
        {
            low = mid + 1;
        }
        else if (counter <= days)
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n, days;
    cin >> n >> days;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    int result = shipWithinDays(weights, days);
    cout << result;
    return 0;
}