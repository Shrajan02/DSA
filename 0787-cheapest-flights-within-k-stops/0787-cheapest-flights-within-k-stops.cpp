// BFS approach
// TC: O(n*E)
// SC: O(n + E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight: flights) {
            int u = flight[0], v = flight[1];
            int cost = flight[2];
            adj[u].push_back({v, cost});
        }

        vector<int> min_cost(n, INT_MAX);
        min_cost[src] = 0;
        queue<pair<int, int>> q;  // {city, price}
        q.push({src, 0});

        int steps = 0;
        while (!q.empty() && steps <= k) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [city, current_price] = q.front();
                q.pop();

                for (auto& [neighbor_city, flight_price]: adj[city]) {
                    int total_price = current_price + flight_price;
                    if (total_price < min_cost[neighbor_city]) {
                        min_cost[neighbor_city] = total_price;
                        q.push({ neighbor_city, total_price });
                    }
                }
            }
            steps++;
        }

        return min_cost[dst] == INT_MAX ? -1 : min_cost[dst];
    }
};