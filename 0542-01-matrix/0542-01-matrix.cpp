// BFS approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
public:
    void bfs(const vector<vector<int>>& mat, vector<vector<int>>& nearest, queue<pair<int, int>>& q) {
        int distance = 0;
        int rows = mat.size(), cols = mat[0].size();

        while (!q.empty()) {
            distance++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [u, v] = q.front();
                q.pop();

                // top
                if (u - 1 >= 0 && nearest[u - 1][v] == -1) {
                    nearest[u - 1][v] = distance;
                    q.push({u - 1, v});
                }

                // bottom
                if (u + 1 < rows && nearest[u + 1][v] == -1) {
                    nearest[u + 1][v] = distance;
                    q.push({u + 1, v});
                }

                // left
                if (v - 1 >= 0 && nearest[u][v - 1] == -1) {
                    nearest[u][v - 1] = distance;
                    q.push({u, v - 1});
                }

                // right
                if (v + 1 < cols && nearest[u][v + 1] == -1) {
                    nearest[u][v + 1] = distance;
                    q.push({u, v + 1});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> nearest(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    nearest[i][j] = 0;
                    q.push({i, j});
                }   
            }
        }

        bfs(mat, nearest, q);

        return nearest;
    }
};