#include "iostream"
#include "vector"

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            // cout<<"initial "<<a[i]<<endl;
            if (result.size() == 0)
            {
                // cout << "a[i] " << a[i] << endl;
                result.push_back(a[i]);
                i++;
            }
            else if (result[result.size() - 1] != a[i])
            {
                // cout << "a[i] " << a[i] << endl;
                result.push_back(a[i]);
                i++;
            }
            else
            {
                i++;
            }
        }
        else if (a[i] > b[j])
        {
            if (result.size() == 0)
            {
                // cout << "b[j] " << b[j] << endl;
                result.push_back(b[j]);
                j++;
            }
            else if (result[result.size() - 1] != b[j])
            {
                // cout << "b[j] " << b[j] << endl;
                result.push_back(b[j]);
                j++;
            }
            else
            {
                j++;
            }
        }
        else if (a[i] == b[j])
        {
            if (result.size() == 0)
            {
                // cout << "b[j]== " << b[j] << endl;
                result.push_back(b[j]);
                i++, j++;
            }
            else if (result[result.size() - 1] != b[j])
            {
                // cout << "b[j]== " << b[j] << endl;
                result.push_back(b[j]);
                i++, j++;
            }
            else
            {
                j++, i++;
            }
        }
    }
    if (i < a.size())
    {
        for (int x = i; x < a.size(); x++)
        {
            if (result[result.size() - 1] != a[x])
            {
                // cout << "a[x] " << a[x] << endl;
                result.push_back(a[x]);
            }
            else
            {
                continue;
            }
        }
    }
    else if (j < b.size())
    {
        for (int x = j; x < b.size(); x++)
        {

            if (result[result.size() - 1] != b[x])
            {
                // cout << "b[x] " << b[x] << endl;
                result.push_back(b[x]);
            }
            else
            {
                continue;
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), result;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    result = findUnion(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}