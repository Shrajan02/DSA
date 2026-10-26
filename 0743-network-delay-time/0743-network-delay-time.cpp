// Dijkstra's Algorithm
// TC: O(E*logV)
// SC: O(V + E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time: times) {
            int u = time[0], v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        vector<int> bestTimes(n + 1, INT_MAX);
        bestTimes[k] = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {time, node}
        pq.push({0, k});

        while (!pq.empty()) {
            auto [current_time, current_node] = pq.top();
            pq.pop();

            if (current_time > bestTimes[current_node]) {
                continue;
            }

            for (auto& [neighbor_node, neighbor_time]: adj[current_node]) {
                int total_time = current_time + neighbor_time;
                if (total_time < bestTimes[neighbor_node]) {
                    bestTimes[neighbor_node] = total_time;
                    pq.push({ total_time, neighbor_node });
                }
            }
        }


        int maxDelayTime = INT_MIN;
        for (int i = 1; i <= n; i++) {
            // impossible to reach any node
            if (bestTimes[i] == INT_MAX) {
                return -1;
            }

            maxDelayTime = std::max(maxDelayTime, bestTimes[i]);
        }

        return maxDelayTime;
    }
};