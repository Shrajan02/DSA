// BFS approach (Kahn's algorithm)
// TC: O(V + E)
// SC: O(V + E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegrees(n);
        for (int i = 0; i < n; i++) {
           outdegrees[i] = graph[i].size();
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<int>> reverse_graph(n);
        for (int i = 0; i < n; i++) {
            for (int neighbor: graph[i]) {
                reverse_graph[neighbor].push_back(i);
            }
        }

        vector<bool> mark_safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            mark_safe[node] = true;

            for (int neighbor: reverse_graph[node]) {
                outdegrees[neighbor]--;
                if (outdegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> safe_nodes;
        for(int i = 0; i < n; i++) {
            if (mark_safe[i]) {
                safe_nodes.push_back(i);
            }
        }

        return safe_nodes;
    }
};