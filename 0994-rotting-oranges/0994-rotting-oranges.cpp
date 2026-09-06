// multi-source bfs approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int fresh_count) {
        int time = 0;
        while (!q.empty() && fresh_count) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto& node = q.front();
                int row = node.first, col = node.second;
                q.pop();

                // top
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    fresh_count--;
                }

                // bottom
                if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    fresh_count--;
                }

                // right
                if (col + 1 < grid[0].size() && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    fresh_count--;
                }

                // left
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    fresh_count--;
                }
            }

            time++;
        }

        // unable to rot all oranges
        if (fresh_count > 0) {
            time = -1;
        }
        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) { 
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
            
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh_count++;  // fresh orange
                }
                else if (grid[i][j] == 2) {
                    q.push({i, j});  // rotten orange
                }
            }
        }

        // no fresh oranges   
        if (fresh_count == 0) {
            return 0;
        }
            
        return bfs(grid, q, fresh_count);
    }
};