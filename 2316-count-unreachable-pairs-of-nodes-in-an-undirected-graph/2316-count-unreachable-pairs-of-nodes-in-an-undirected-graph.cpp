// Union-Find approach
// TC: O(E.alpha(n))
// SC: O(n)
using ll = long long;
class Solution {
private:
    int find(int node, vector<int>& parents) {
        if (node == parents[node]) {
            return node;
        }

        return parents[node] = find(parents[node], parents);
    }

    void unionBySize(vector<int>& parents, vector<ll>& size, int u, int v) {
        int u_root = find(u, parents);
        int v_root = find(v, parents);

        if (u_root == v_root) {
            return;
        }

        if (size[u_root] > size[v_root]) {
            parents[v_root] = u_root;
            size[u_root] += size[v_root];
        }
        else {
            parents[u_root] = v_root;
            size[v_root] += size[u_root];
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        vector<ll> size(n, 1);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        for (auto& edge: edges) {
            unionBySize(parents, size, edge[0], edge[1]);
        }
        
        ll count = 1LL * n * (n - 1) / 2;
        for (int k = 0; k < n; k++) {
            // only consider roots of disjoint sets
            if (parents[k] == k && size[k] > 1) {
                count -= (size[k] * (size[k] - 1) / 2);
            }
        }

        return count;
    }
};