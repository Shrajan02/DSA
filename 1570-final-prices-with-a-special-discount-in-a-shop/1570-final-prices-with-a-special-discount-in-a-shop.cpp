class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            while (j < n) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }
                j++;
            }
        }
        return prices;
    }
};