// BFS approach
// TC: O(V + E)
// SC: O(V)
class Solution {
private:
    bool bfs(const vector<vector<int>>& graph, vector<int>& colors, int current_node, int current_color) {
        queue<int> q;
        q.push(current_node);
        colors[current_node] = current_color;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor: graph[node]) {
                if (colors[neighbor] == colors[node]) {
                    return false;
                }

                if (colors[neighbor] == -1) {
                    q.push(neighbor);
                    colors[neighbor] = 1 - colors[node];
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int v = 0; v < n; v++) {
            if (colors[v] == -1 && !bfs(graph, colors, v, 0)) {
                return false;
            }
        }

        return true;
    }
};