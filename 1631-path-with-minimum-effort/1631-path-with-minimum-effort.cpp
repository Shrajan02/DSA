// Dijkstra's Algorithm approach
// m -> rows, n -> columns
// TC: O(m*n*log(mn))
// SC: O(m*n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using Cell = std::tuple<int, int, int>;
        int rows = heights.size(), columns = heights[0].size();

        vector<vector<int>> efforts(rows, vector<int>(columns, INT_MAX));
        efforts[0][0] = 0;
        std::priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        pq.push({ 0, 0, 0 });
        
        vector<int> dr = { -1, 0, 0, 1 };
        vector<int> dc = { 0, -1, 1, 0 };

        while (!pq.empty()) {
            auto [current_effort, row, col] = pq.top();
            pq.pop();

            if (row == rows - 1 && col == columns - 1) {
                return current_effort;
            }

            // skip if better effort for this cell
            if (current_effort > efforts[row][col]) {
                continue;
            }

            for (int i = 0; i < dr.size(); i++) {
                int neighbor_row = row + dr[i];
                int neighbor_col = col + dc[i];

                // check bounds
                if (neighbor_row < 0 || neighbor_row >= rows || neighbor_col < 0 || neighbor_col >= columns) {
                    continue;
                }

                int step_height = std::abs(heights[neighbor_row][neighbor_col] - heights[row][col]);
                int new_effort = std::max(current_effort, step_height);

                if (new_effort < efforts[neighbor_row][neighbor_col]) {
                    efforts[neighbor_row][neighbor_col] = new_effort;
                    pq.push({ new_effort, neighbor_row, neighbor_col });
                }
            }
        }

        return 0; // won't reach
    }
};