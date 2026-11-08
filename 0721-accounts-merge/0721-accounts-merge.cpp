// Union-Find approach
// TC: O(n + m*α(n) + m*log(m))
// SC: O(n + m)
// n -> number of accounts, m -> total number of emails
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

    void unionAccounts(int u, int v) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
        ranks.resize(n, 1);

        unordered_map<string, int> emailToIndex;  // email -> account index
        for (int i = 0; i < n; i++) {
            auto& account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                string email = account[j];
                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = i;
                }
                // union current index with previously mapped account index
                else {
                    unionAccounts(i, emailToIndex[email]);
                }
            }
        }

        // group emails by ultimate parent indexes
        vector<vector<string>> mergedMails(n);
        for (auto& [email, index]: emailToIndex) {
            int node = find(index);  // only for ultimate parents
            mergedMails[node].push_back(email);
        }

        vector<vector<string>> mergedAccounts;
        for (int i = 0; i < n; i++) {
            if (mergedMails[i].empty()) {
                continue;
            }

            vector<string> current;
            current.push_back(accounts[i][0]);
            std::sort(mergedMails[i].begin(), mergedMails[i].end());
            for (auto& email: mergedMails[i]) {
                current.push_back(email);
            }

            mergedAccounts.push_back(current);
        }

        return mergedAccounts;
    }
};