// TC: O(m * n)
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // top
                if (i > 0 && mat[i][j] < mat[i-1][j]) {
                    continue;
                }
                // left
                if (j > 0 && mat[i][j] < mat[i][j-1]) {
                    continue;
                }
                // bottom
                if (i < m-1 && mat[i][j] < mat[i+1][j]) {
                    continue;
                }
                // right
                if (j < n-1 && mat[i][j] < mat[i][j+1]) {
                    continue;
                }
                return {i, j};
            }
        }
        return {};
    }
};