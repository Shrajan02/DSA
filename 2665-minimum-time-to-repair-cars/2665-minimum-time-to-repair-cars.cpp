// Space-optimized Binary Search approach
// TC: O(m * log(cars))
// SC: O(1)
class Solution {
private:
    bool repairCars(vector<int>& ranks, long long mid, int cars) {
        // r -> rank, n -> cars, T -> mid
        // r * n^2 <= T
        // n <= sqrt(T/r)
        int m = ranks.size();
        long long total = 0;
        for (int i = 0; i < m; i++) {
            total += (long long)sqrt(mid / ranks[i]);
        }
        return (cars <= total);
    }   

public:
    long long repairCars(vector<int>& ranks, int cars) {
        // search space : 1 - 400
        long long low = *min_element(ranks.begin(), ranks.end());
        long long high = *max_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            bool possible = repairCars(ranks, mid, cars);
            if (possible) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};