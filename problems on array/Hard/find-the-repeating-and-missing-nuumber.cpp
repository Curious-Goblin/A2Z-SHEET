#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        map<int, int> elements;
        int sum_of_all_elements = (arr.size() * (arr.size() + 1)) / 2, sum_of_array = 0, sum_of_unique_elements = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            elements[arr[i]] = i;
            sum_of_array += arr[i];
        }
        for (auto it : elements)
        {
            sum_of_unique_elements += it.first;
        }
        int missing_element = sum_of_all_elements - sum_of_unique_elements;
        int element = missing_element - sum_of_all_elements + sum_of_array;
        return {element, missing_element};
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    vector<int> result = s.findTwoElement(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}