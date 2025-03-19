// Binary Search on Answers approach
// TC: O(n * log(max_element))
// SC: O(1)
class Solution {
private:
    bool allocateCandies(vector<int>& candies, int candidate, long long k) {
        long long piles = 0;
        for (int candy: candies) {
            piles += candy / candidate;
            // early exit
            if (piles >= k) {
                return true;
            }
        }
        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;   // avoid division by 0
        int high = *max_element(candies.begin(), candies.end());
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool possible = allocateCandies(candies, mid, k);
            if (possible) {
                low = mid + 1;
                result = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};