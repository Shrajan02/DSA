// Modified Dijkstra approach (Minimax Path Problem)
// TC: O(N^2.logN)
// SC: O(N^2)
class Solution {
private:    
    using CellTuple = std::tuple<int, int, int>;

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<CellTuple, vector<CellTuple>, greater<CellTuple>> pq;
        pq.push({ grid[0][0], 0, 0 });
        vector<vector<bool>> visited(n, vector<bool>(n));
        visited[0][0] = true;

        vector<int> dr = { -1, 0, 0, 1 };
        vector<int> dc = { 0, 1, -1, 0 };

        int maxElevation = INT_MIN;
        while (!pq.empty()) {
            auto [elevation, i, j] = pq.top();
            pq.pop();

            maxElevation = std::max(maxElevation, elevation);
            if (i == n - 1 && j == n - 1) {
                return maxElevation;
            }

            for (int k = 0; k < dr.size(); k++) {
                int neighbor_row = i + dr[k];
                int neighbor_col = j + dc[k];

                // check bounds
                if (neighbor_row < 0 || neighbor_row >= n || neighbor_col < 0 || neighbor_col >= n) {
                    continue;
                }
                
                if (!visited[neighbor_row][neighbor_col]) {
                    visited[neighbor_row][neighbor_col] = true;
                    pq.push({ grid[neighbor_row][neighbor_col], neighbor_row, neighbor_col });
                }
            }
        }

        return -1;
    }
};