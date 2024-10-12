class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        // First identify which half is sorted and use BS on that half
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // right half is sorted
            else {
                if (nums[high] >= target && nums[mid] <= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};