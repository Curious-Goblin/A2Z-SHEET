#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

// An adjacency list is a data structure used to represent a graph where
// each node in the graph stores a list of its neighboring vertices.

class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> result(V);
        map<int, set<int>> adList;

        for (int i = 0; i < edges.size(); i++)
        {
            adList[edges[i].first].insert(edges[i].second);
            adList[edges[i].second].insert(edges[i].first);
        }

        for (auto it : adList)
        {
            result[it.first] = vector<int>(it.second.begin(), it.second.end());
        }

        return result;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    Solution s;
    vector<vector<int>> result = s.printGraph(V, edges);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}