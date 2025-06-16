#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &result)
    {
        visited[s] = true;
        result.push_back(s);
        for (int x : adj[s])
        {
            if (!visited[x])
            {
                dfsRec(adj, visited, x, result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<bool> visited(v, false);
        vector<int> result;
        dfsRec(adj, visited, 0, result);
        return result;
    }
};

int main()
{
    int n, r;
    cin >> n;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        vector<int> temp(r);
        for (int j = 0; j < r; j++)
        {
            cin >> temp[j];
        }
        adj.push_back(temp);
    }
    Solution s;
    vector<int> result = s.dfs(adj);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}