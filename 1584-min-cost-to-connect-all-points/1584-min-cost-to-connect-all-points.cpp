// Prim's algorithm
// TC: O(n^2.log(n))
// SC: O(n^2)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // build adjacency list
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);  // {index, distance}
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, val});
                adj[j].push_back({i, val});
            }
        }

        // applying prim's
        int min_cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {distance, index}
        pq.push({0, 0});
        vector<bool> inMST(n);

        while (!pq.empty()) {
            auto [current_distance, current_point] = pq.top();
            pq.pop();

            if (inMST[current_point]) {
                continue;
            }

            inMST[current_point] = true;
            min_cost += current_distance;

            for (auto& [neighbor_point, neighbor_distance]: adj[current_point]) {
                if (!inMST[neighbor_point]) {
                    pq.push({neighbor_distance, neighbor_point});
                }
            }
        }

        return min_cost;
    }
};