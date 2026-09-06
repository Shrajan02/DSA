// DFS approach
// TC: O(V^2)
// SC: O(V)
class Solution {
public:
    void dfs(int node, const vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (node != neighbor && isConnected[node][neighbor] == 1 && visited[neighbor] == 0) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int count = 0;
        vector<int> visited(v);

        for (int col = 0; col < v; col++) {
            if (visited[col] == 0) {
                count++;
                dfs(col, isConnected, visited);
            }
        }

        return count;
    }
};