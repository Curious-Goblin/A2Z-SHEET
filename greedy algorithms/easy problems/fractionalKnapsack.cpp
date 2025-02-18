#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        map<double, int, greater<double>> unitVal;
        for (int i = 0; i < val.size(); i++)
        {
            if (unitVal.find(double((double)val[i] / (double)wt[i])) == unitVal.end())
            {
                unitVal[double((double)val[i] / (double)wt[i])] = wt[i];
            }
            else
            {
                unitVal[double((double)val[i] / (double)wt[i])] += wt[i];
            }
        }
        // for(auto &it:unitVal){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        double maxVal = 0.000000;
        for (auto &it : unitVal)
        {
            if (capacity > 0)
            {
                if (capacity - it.second >= 0)
                {
                    maxVal += it.first * it.second;
                    capacity -= it.second;
                }
                else
                {
                    maxVal += it.first * capacity;
                    capacity = 0;
                }
            }
        }

        return round(maxVal * 1e6) / 1e6;
    }
};

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    Solution solve;
    cout << solve.fractionalKnapsack(val, wt, capacity);
    return 0;
}