// DFS approach (graph coloring)
// TC: O(V + E)
// SC: O(V)
// bipartite -> if you can color every node with 2 colors such that adjacent nodes have different colors
// odd-length cycles are NEVER bipartite, rest all are bipartite
class Solution {
private:
    bool dfs(const vector<vector<int>>& graph, vector<int>& colors, int current_node, int current_color) {
        colors[current_node] = current_color;

        for (int neighbor: graph[current_node]) {
            if (colors[neighbor] == current_color) {
                return false;
            }

            int reverse_color = 1 - current_color;
            if (colors[neighbor] == -1 && !dfs(graph, colors, neighbor, reverse_color)) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);  // -1 -> no color, 0 -> one color, 1 -> other color
        
        for (int v = 0; v < n; v++) {
            if (colors[v] == -1 && !dfs(graph, colors, v, 0)) {
                return false;
            }
        }

        return true;
    }
};
