#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<bool> visited(V, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        vector<int> result;
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            result.push_back(current);
            for (int x : adj[current])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
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
    vector<int> result = s.bfs(adj);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}