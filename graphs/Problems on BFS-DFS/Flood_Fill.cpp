#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;

        int m = image.size(), n = image[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        visited[sr][sc] = true;

        queue<pair<int, int>> q;

        m = m - 1, n = n - 1;

        q.push({sr, sc});

        while (!q.empty())
        {
            int current = image[q.front().first][q.front().second];
            int row = q.front().first, coloumn = q.front().second;
            image[row][coloumn] = color;
            q.pop();
            if (row - 1 >= 0)
            {
                if (image[row - 1][coloumn] == current && visited[row - 1][coloumn] == false)
                {
                    q.push({row - 1, coloumn});
                    visited[row - 1][coloumn] = true;
                }
            }
            if (coloumn - 1 >= 0)
            {
                if (image[row][coloumn - 1] == current && visited[row][coloumn - 1] == false)
                {
                    q.push({row, coloumn - 1});
                    visited[row][coloumn - 1] = true;
                }
            }
            if (row + 1 <= m)
            {
                if (image[row + 1][coloumn] == current && visited[row + 1][coloumn] == false)
                {
                    q.push({row + 1, coloumn});
                    visited[row + 1][coloumn] = true;
                }
            }
            if (coloumn + 1 <= n)
            {
                if (image[row][coloumn + 1] == current && visited[row][coloumn + 1] == false)
                {
                    q.push({row, coloumn + 1});
                    visited[row][coloumn + 1] = true;
                }
            }
        }
        return image;
    }
};

int main()
{
    int n, m, sr, sc, color;
    cin >> m >> n >> sr >> sc >> color;
    vector<vector<int>> image(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }
    Solution s;
    vector<vector<int>> result = s.floodFill(image, sr, sc, color);
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