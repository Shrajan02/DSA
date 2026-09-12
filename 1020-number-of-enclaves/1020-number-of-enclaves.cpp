// BFS approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
private:
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        while (!q.empty()) {
            auto [u, v] = q.front();
            q.pop();

            // top
            if (u - 1 >= 0 && grid[u - 1][v] == 1) {
                grid[u - 1][v] = 0;
                q.push({u - 1, v});
            }

            // bottom
            if (u + 1 < grid.size() && grid[u + 1][v] == 1) {
                grid[u + 1][v] = 0;
                q.push({u + 1, v});
            }

            // left
            if (v - 1 >= 0 && grid[u][v - 1] == 1) {
                grid[u][v - 1] = 0;
                q.push({u, v - 1});
            }

            // right
            if (v + 1 < grid[0].size() && grid[u][v + 1] == 1) {
                grid[u][v + 1] = 0;
                q.push({u, v + 1});
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // push edge nodes with '0' to q
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        bfs(grid, q);
        
        int enclaves = 0;
        for (auto& row: grid) {
            for (auto& cell: row) {
                if (cell == 1) {
                    enclaves++;
                }
            }
        }

        return enclaves;   
    }
};