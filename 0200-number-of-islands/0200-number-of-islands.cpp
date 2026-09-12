// DFS approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
private:
    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int u, int v) {
        visited[u][v] = true;

        // top
        if (u - 1 >= 0 && !visited[u - 1][v] && grid[u - 1][v] == '1') {
            dfs(grid, visited, u - 1, v);
        }

        // bottom
        if (u + 1 < grid.size() && !visited[u + 1][v] && grid[u + 1][v] == '1') {
            dfs(grid, visited, u + 1, v);
        }

        // left
        if (v - 1 >= 0 && !visited[u][v - 1] && grid[u][v - 1] == '1') {
            dfs(grid, visited, u, v - 1);
        }

        // right
        if (v + 1 < grid[0].size() && !visited[u][v + 1] && grid[u][v + 1] == '1') {
            dfs(grid, visited, u, v + 1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return islands;
    }
};