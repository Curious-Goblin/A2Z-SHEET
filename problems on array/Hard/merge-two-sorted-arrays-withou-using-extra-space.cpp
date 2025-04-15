#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    // o(max(n,m)+ nlogn mlogm) optimal approach 1
    // intution was that after merging one thing was clear that a will contain all the smaller elements
    // while b will contain all the larger elements so we are swapping the larger elements of a until the
    // smallest element of b is greater than the largest element of a;
    // void mergeArrays(vector<int> &a, vector<int> &b)
    // {
    //     int left = a.size()-1;
    //     int right = 0;
    //     while(left >=0 && right < b.size()){
    //         if(a[left]>b[right]){
    //             swap(a[left],b[right]);
    //             left--;
    //             right++;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     sort(a.begin(),a.end());
    //     sort(b.begin(),b.end());
    // }

    // optimal approach 2 this method is called shell short
    // time complexity = O((n+m)*(log(n+m))
    void mergeArrays(vector<int> &a, vector<int> &b)
    {
        int left = 0, right = 0, gap = ceil((double)(a.size() + b.size()) / 2);
        while (gap >= 1)
        {
            left = 0, right = left + gap;
            while (right <= ((a.size() + b.size()) - 1))
            {
                if (right < a.size())
                {
                    if (a[left] > a[right])
                    {
                        swap(a[left], a[right]);
                    }
                }
                else if (right >= a.size())
                {
                    if (left < a.size())
                    {
                        if (a[left] > b[right - a.size()])
                        {
                            swap(a[left], b[right - a.size()]);
                        }
                    }
                    else
                    {
                        if (b[left - a.size()] > b[right - a.size()])
                        {
                            swap(b[left - a.size()], b[right - a.size()]);
                        }
                    }
                }
                left++, right++;
            }
            if (gap == 1)
            {
                break;
            }
            gap = ceil((double)(gap) / 2);
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    Solution s;
    s.mergeArrays(a, b);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}