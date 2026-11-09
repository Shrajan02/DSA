// Union-Find approach
// TC: O(n*α(n))
// SC: O(n)
class Solution {
private:
    vector<int> parents;
    vector<int> ranks;

    int find(int x) {
        if (x == parents[x]) {
            return x;
        }

        return parents[x] = find(parents[x]);
    }

    void unionStones(int u, int v) {
        int u_root = find(u);
        int v_root = find(v);

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
    int removeStones(vector<vector<int>>& stones) {
        // row nodes -> 0 - 10000
        // column nodes -> 10001 - 20001
        // DSU size -> 20002
        int n = stones.size();
        parents.resize(20002);
        ranks.resize(20002, 1);
        std::iota(parents.begin(), parents.end(), 0);

        // union each stone's row & column as unique indices
        int offset = 10001;
        unordered_set<int> used;
        for (auto& coordinate: stones) {
            int r = coordinate[0];
            int c = coordinate[1] + offset;
            unionStones(r, c);
            
            used.insert(r);
            used.insert(c);
        }

        // count distinct roots
        int groups = 0;
        for (auto& x: used) {
            if (x == find(x)) {
                groups++;
            }
        }

        // max stones removed = total stones - number of components
        return (n - groups);
    }
};