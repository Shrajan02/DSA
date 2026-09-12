// DFS approach
// TC: O(m*n)
// SC: O(1)
class Solution {
private:
    void dfs(vector<vector<char>>& board, int u, int v) {
        // top
        if (u - 1 >= 0 && board[u - 1][v] == 'O') {
            board[u - 1][v] = 'S';
            dfs(board, u - 1, v);
        }
        
        // bottom
        if (u + 1 < board.size() && board[u + 1][v] == 'O') {
            board[u + 1][v] = 'S';
            dfs(board, u + 1, v);
        }
        
        // left
        if (v - 1 >= 0 && board[u][v - 1] == 'O') {
            board[u][v - 1] = 'S';
            dfs(board, u, v - 1);
        }
        
        // right
        if (v + 1 < board[0].size() && board[u][v + 1] == 'O') {
            board[u][v + 1] = 'S';
            dfs(board, u, v + 1);
        }
    
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // only traverse edges
                if (i == 0 || j == 0 || (i == m - 1) || j == (n - 1)) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'S';
                        dfs(board, i, j);  // mark safe neighbors
                    }
                }
            }
        }
        
        // transformation
        for (auto& row: board) {
            for (auto& region: row) {
                if (region == 'O') {
                    region = 'X';
                }
                else if (region == 'S') {
                    region = 'O';
                }
            }
        }
    }
};
