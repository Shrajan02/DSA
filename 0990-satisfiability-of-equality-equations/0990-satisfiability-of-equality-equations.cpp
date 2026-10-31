// Union-Find approach
// TC: O(n)
// SC: O(1)
class Solution {
private:
    int find (int ch, vector<int>& parents) {
        if (ch == parents[ch]) {
            return ch;
        }

        return parents[ch] = find(parents[ch], parents);
    }

    bool unionByRank(vector<int>& parents, vector<int>& ranks, int x, int y) {
        int x_root = find(x, parents);
        int y_root = find(y, parents);

        if (x_root == y_root) {
            return false;
        }

        if (ranks[x_root] > ranks[y_root]) {
            parents[y_root] = x_root;
        }
        else if (ranks[y_root] > ranks[x_root]) {
            parents[x_root] = y_root;
        }
        else {
            parents[y_root] = x_root;
            ranks[x_root]++;
        }

        return true;
    }

public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parents(26);
        vector<int> ranks(26, 1);

        // initialize parent as its own set
        for (int i = 0; i < 26; i++) {
            parents[i] = i;
        }

        // only process '=='
        for (string& equation: equations) {
            if (equation[1] == '=') {
                unionByRank(parents, ranks, equation[0] - 'a', equation[3] - 'a');
            }
        }

        // next process '!='
        for (string& equation: equations) {
            if (equation[1] == '!') {
                // both x and y must not have same roots, check for contradiction
                if (find(equation[0] - 'a', parents) == find(equation[3] - 'a', parents)) {
                    return false;
                }
            }
        }

        return true;
    }
};