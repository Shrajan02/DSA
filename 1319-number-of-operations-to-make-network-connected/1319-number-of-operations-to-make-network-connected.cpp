// Union-Find approach
// TC: O(e*α(n))
// SC: O(n)
class Solution {
private:
    int find(int computer, vector<int>& parents) {
        if (computer == parents[computer]) {
            return computer;
        }

        return parents[computer] = find(parents[computer], parents);
    }

    void unionComputers(vector<int>& parents, vector<int>& ranks, int u, int v) {
        int u_root = find(u, parents);
        int v_root = find(v, parents);

        // same component
        if (u_root == v_root) {
            return;
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
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // for 'n' nodes => minimum (n - 1) edges
        int e = connections.size();
        if (e < n - 1) {
            return -1;
        }

        vector<int> parents(n);
        vector<int> ranks(n, 1);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for (auto& connection: connections) {
            unionComputers(parents, ranks, connection[0], connection[1]);
        }

        // count connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i, parents) == i) {
                components++;
            }
        }

        return (components - 1);
    }
};