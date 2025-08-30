class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; i + j < n; j++) {
                temp.push_back(grid[i + j][j]);
            }
            std::sort(temp.begin(), temp.end(), greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = temp[j];
            }
        }

        for (int j = 1; j < n; j++) {
            vector<int> temp;
            for (int i = 0; j + i < n; i++) {
                temp.push_back(grid[i][j + i]);
            }
            std::sort(temp.begin(), temp.end());
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = temp[i];
            }
        }
        return grid;
    }
};