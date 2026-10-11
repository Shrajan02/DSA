// BFS approach
// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // edge case: when either source or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        queue<pair<int, int>> q;
        q.push({0, 0});

        // directional arrays
        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        int min_distance = 0;
        while (!q.empty()) {
            int size = q.size();
            min_distance++;

            for (int k = 0; k < size; k++) {
                auto cell = q.front();
                int r = cell.first, c = cell.second;
                q.pop();

                // when reaching last cell
                if (r == n - 1 && c == n - 1) {
                    return min_distance;
                }

                for (int i = 0; i < dr.size(); i++) {
                    int neighbor_row = r + dr[i];
                    int neighbor_col = c + dc[i];

                    if (neighbor_row < 0 || neighbor_row >= n || neighbor_col < 0 || neighbor_col >= n) {
                        continue;
                    }

                    if (grid[neighbor_row][neighbor_col] == 0 && !visited[neighbor_row][neighbor_col]) {
                        visited[neighbor_row][neighbor_col] = true;
                        q.push({neighbor_row, neighbor_col});
                    }    
                }
            }
        }
        
        return -1;
    }
};