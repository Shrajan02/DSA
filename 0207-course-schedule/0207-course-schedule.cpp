// Kahn's algorithm (Topological Sort)
// TC: O(V + E)
// SC: O(V + E)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int e = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < e; i++) {
            auto& node = prerequisites[i];
            adj[node[1]].push_back(node[0]);
        }
   
        // Kahn's Algorithm
        // 1. Build indegree list
        vector<int> indegrees(numCourses, 0);
        for (const auto& neighbors: adj) {
            for (int edge: neighbors) {
                indegrees[edge]++;
            }
        }

        // 2. Initialize queue by pushing elements with indegree 0
        queue<int> q;
        for (int node = 0; node < numCourses; node++) {
            if (indegrees[node] == 0) {
                q.push(node);
            }
        }

        // 3. Run BFS
        int visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            for (int neighbor: adj[node]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // if visited nodes match total nodes, no cycle exists
        return (visited == numCourses);
    }
};