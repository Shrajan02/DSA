// Greedy Approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // don't jump, go step by step
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > minPrice) {
                maxProfit += (prices[i] - minPrice);
            }
            minPrice = prices[i];
        }
        return maxProfit;
    }
};