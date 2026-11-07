// Kruskal's algorithm
// TC: O(n^2.log(n))
// SC: O(n^2)
class Solution {
private:
    int find(int point, vector<int>& parents) {
        if (point == parents[point]) {
            return point;
        }

        return parents[point] = find(parents[point], parents);
    }

    bool unionPoints(vector<int>& parents, vector<int>& ranks, int u, int v) {
        int u_root = find(u, parents);
        int v_root = find(v, parents);

        // same component
        if (u_root == v_root) {
            return false;
        }

        if (ranks[u_root] > ranks[v_root]) {
            parents[v_root] = u_root;
        }
        else if (ranks[v_root] > ranks[u_root]) {
            parents[u_root] = v_root;
        }
        else {
            parents[v_root] = u_root;
            ranks[u_root]++;
        }

        return true;
    }


public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // build adjacency list
        int n = points.size();
        vector<vector<int>> edges;  // {source, destination, distance}
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, distance});
            }
        }

        // sort edges by distance in ascending order
        std::sort(edges.begin(), edges.end(), [](auto& u, auto& v) {
            return u[2] < v[2];
        });

        // applying kruskal's
        vector<int> parents(n);
        vector<int> ranks(n, 1);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        int min_cost = 0;
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            int distance = edge[2];
            if (unionPoints(parents, ranks, u, v)) {
                min_cost += distance;
            }
        }
        
        return min_cost;
    }
};
