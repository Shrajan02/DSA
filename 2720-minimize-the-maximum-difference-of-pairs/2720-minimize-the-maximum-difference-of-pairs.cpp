// Binary Search on Answers approach
// TC: O(n * log(n))
// SC: O(1)
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = INT_MAX;
        int low = 0, high = nums[n - 1] - nums[0];
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            bool isPossible = calculatePairs(nums, mid, n, p);
            if (isPossible) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }

private:
    bool calculatePairs(vector<int>& nums, int mid, int n, int p) {
        int totalPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            int first = nums[i], second = nums[i + 1];
            // since array is sorted, no need of absolute
            if ((second - first) <= mid) {
                totalPairs++;
                i++;
            }
        }
        return (totalPairs >= p);
    }

};