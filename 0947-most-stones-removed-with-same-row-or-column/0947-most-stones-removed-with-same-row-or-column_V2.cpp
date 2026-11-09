// DFS approach
// TC: O(n^2)
// SC: O(n)
class Solution {
private:    
    void dfs(const vector<vector<int>>& stones, vector<bool>& visited, int current) {
        visited[current] = true;

        int r = stones[current][0];
        int c = stones[current][1];
        for (int neighbor = 0; neighbor < stones.size(); neighbor++) {
            // only visit stones sharing the same row or column
            if (!visited[neighbor] && (stones[neighbor][0] == r || stones[neighbor][1] == c)) {
                dfs(stones, visited, neighbor);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n);

        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(stones, visited, i);
                groups++;
            }
        }

        // only one stone left per component
        return (n - groups);
    }
};
