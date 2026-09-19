// BFS approach (Kahn's algorithm)
// TC: O(V + E + VlogV)
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

        vector<int> safe_nodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe_nodes.push_back(node);

            for (int neighbor: reverse_graph[node]) {
                outdegrees[neighbor]--;
                if (outdegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        ranges::sort(safe_nodes);

        return safe_nodes;
    }
};