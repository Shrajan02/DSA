// greedy approach (out of place)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // forward pass
        vector<int> forward(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                forward[i] += forward[i - 1];
            }
        }

        // backward pass
        vector<int> backward(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                backward[i] += backward[i + 1];
            }
        }

        int min_candies = 0;
        for (int i = 0; i < n; i++) {
            min_candies += std::max(forward[i], backward[i]);
        }

        return min_candies;
    }
};