// Dijkstra Algorithm
// TC: O(V.ElogV)
// SC: O(V + E)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // run dijkstra n times
        int minCity = 0, minNeighbors = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> minDistance(n, INT_MAX);
            minDistance[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({i, 0});
            int neighbors = 0;

            while (!pq.empty()) {
                auto [current_city, current_distance] = pq.top();
                pq.pop();

                if (current_distance > distanceThreshold || current_distance > minDistance[current_city]) {
                    continue;
                }

                for (auto& [neighbor_city, neighbor_distance]: adj[current_city]) {
                    int total_distance = current_distance + neighbor_distance;
                    if (total_distance <= distanceThreshold && total_distance <= minDistance[neighbor_city]) {
                        minDistance[neighbor_city] = total_distance;
                        pq.push({ neighbor_city, total_distance });
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                // source & destination cannot be same
                if (j == i || minDistance[j] == INT_MAX) {
                    continue;
                }
                neighbors++;
            }

            // city with smallest neighbors get priority
            if (neighbors <= minNeighbors) {
                minNeighbors = neighbors;
                minCity = i;
            }
        }

        return minCity;
    }
};