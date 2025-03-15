// Kadane's Algorithm (DP approach)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            minPrice = min(prices[i], minPrice);
            maxProfit = max(prices[i] - minPrice, maxProfit);
        }
        return maxProfit;
    }
};