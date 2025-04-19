// Binary Search approach
// TC: O(nlogn)
// SC: O(logn)
#define ll long long
class Solution {
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll countFair = 0;
        for (int i = 0; i < n; i++) {
            int low = lower_bound(nums, i + 1, n - 1, lower - nums[i]);
            int high = lower_bound(nums, i + 1, n - 1, upper - nums[i] + 1);
            countFair += 1LL * (high - low);
        }
        return countFair;
    }

private:
    ll lower_bound(vector<int>& nums, int low, int high, int element) {
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] >= element) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};