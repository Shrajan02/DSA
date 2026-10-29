// Union-Find approach
// TC: O(m*n)
// SC: O(m*n)
class Solution {
private:
    auto find(pair<int, int> cell, vector<vector<pair<int, int>>>& parents) {
        auto [r, c] = cell;
        if (cell == parents[r][c]) {
            return cell;
        }

        return parents[r][c] = find(parents[r][c], parents);
    }

    bool unionSets(vector<vector<pair<int, int>>>& parents, vector<vector<int>>& ranks, int ur, int uc, int vr, int vc) {
        auto [ur_root, uc_root] = find({ur, uc}, parents);
        auto [vr_root, vc_root] = find({vr, vc}, parents);

        // cycle detected if same parent
        if (ur_root == vr_root && uc_root == vc_root) {
            return true;
        }

        if (ranks[ur_root][uc_root] > ranks[vr_root][vc_root]) {
            parents[vr_root][vc_root] = {ur_root, uc_root};
        }
        else if (ranks[vr_root][vc_root] > ranks[ur_root][uc_root]) {
            parents[ur_root][uc_root] = {vr_root, vc_root};
        }
        else {
            parents[vr_root][vc_root] = {ur_root, uc_root};
            ranks[ur_root][uc_root]++;
        }

        return false;
    }

    bool isCycle(vector<vector<char>>& grid, vector<vector<pair<int, int>>>& parents, vector<vector<int>>& ranks, int u, int v) {
        int m = grid.size(), n = grid[0].size();

        // bottom
        if (u + 1 < m && grid[u][v] == grid[u + 1][v]) {
            if (unionSets(parents, ranks, u, v, u + 1, v)) {
                return true;
            }
        }

        // right
        if (v + 1 < n && grid[u][v] == grid[u][v + 1]) {
            if (unionSets(parents, ranks, u, v, u, v + 1)) {
                return true;
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> parents(m, vector<pair<int, int>>(n));
        vector<vector<int>> ranks(m, vector<int>(n, 1));

        // initially all nodes start as its own set
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                parents[i][j] = {i, j};
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isCycle(grid, parents, ranks, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};