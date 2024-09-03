class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0, mini = INT_MAX;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            mini = min(mini, prices[i]);
            best = max(best, prices[i] - mini);
        }
        return best;
    }
};