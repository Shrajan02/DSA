class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // Space-optimized DP: O(n)
        int n = values.size();
        int maxScore = 0;
        int prefixMax = values[0];

        for (int j = 1; j < n; j++) {
            // score = (values[i] + i) + (values[j] - j)
            maxScore = max(maxScore, prefixMax + values[j] - j);  // right part
            prefixMax = max(prefixMax, values[j] + j);  // left part
        }
        return maxScore;
    }
};