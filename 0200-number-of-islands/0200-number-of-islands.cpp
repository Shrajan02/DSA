// DFS approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int u, int v) {
        grid[u][v] = '0';

        // top
        if (u - 1 >= 0 && grid[u - 1][v] == '1') {
            dfs(grid, u - 1, v);
        }

        // bottom
        if (u + 1 < grid.size() && grid[u + 1][v] == '1') {
            dfs(grid, u + 1, v);
        }

        // left
        if (v - 1 >= 0 && grid[u][v - 1] == '1') {
            dfs(grid, u, v - 1);
        }

        // right
        if (v + 1 < grid[0].size() && grid[u][v + 1] == '1') {
            dfs(grid, u, v + 1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};