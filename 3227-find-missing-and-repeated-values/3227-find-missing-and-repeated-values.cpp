// Math approach
// TC: O(n^2) 
// SC: O(1)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long total = 1LL * n * n;
        long long sum = 0, sqrSum = 0;

        // Calculate actual sum and squared sum from grid
        for (auto& row: grid) {
            for (int val: row) {
                sum += val;
                sqrSum += 1LL * val * val;
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y, sqrDiff = x² - y²
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};