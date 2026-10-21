// Dijkstra's Algorithm
// TC: O(ElogV + V)
// SC: O(V + E)
#define ll long long
const ll MOD = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, ll>>> adj(n);
        for (const auto& road: roads) {
            int u = road[0], v = road[1];
            ll time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<ll> minTimes(n, LLONG_MAX);
        minTimes[0] = 0;
        vector<ll> ways(n, 0);
        ways[0] = 1;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;  // {total_time, road}
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [current_time, current_road] = pq.top();
            pq.pop();

            // skip for larger times
            if (current_time > minTimes[current_road]) continue;

            for (auto& [neighbor_road, neighbor_time]: adj[current_road]) {
                ll total_time = current_time + neighbor_time;
                // strictly shorter time
                if (total_time < minTimes[neighbor_road]) {
                    minTimes[neighbor_road] = total_time;
                    ways[neighbor_road] = ways[current_road];
                    pq.push({ total_time, neighbor_road });
                }
                // exact same shortest time
                else if (total_time == minTimes[neighbor_road]) {
                    ways[neighbor_road] = (ways[current_road] + ways[neighbor_road]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};