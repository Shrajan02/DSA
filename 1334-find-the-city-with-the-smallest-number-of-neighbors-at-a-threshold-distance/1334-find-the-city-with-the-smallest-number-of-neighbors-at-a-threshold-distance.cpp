// Floyd-Warshall Algorithm
// TC: O(n^3)
// SC: O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // build distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int city = 0; city < n; city++) {
            dist[city][city] = 0;
        }

        for (auto& edge: edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        };

        // run floyd-warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        // find city with min reachable neighbors
        int minCity = -1, minNeighbors = n;
        for (int city = 0; city < n; city++) {
            int neighbor_cities = 0;
            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (city != neighbor && dist[city][neighbor] <= distanceThreshold) {
                    neighbor_cities++;
                }
            }

            if (neighbor_cities <= minNeighbors) {
                minNeighbors = neighbor_cities;
                minCity = city;
            }
        }

        return minCity;
    }
};