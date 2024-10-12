class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // Ensure mid is either odd/even, so pairs can be checked correctly
            if (mid % 2 == 0) {
                mid--;
            }

            if (nums[mid] == nums[mid - 1]) {
                low = mid + 1;
            } else if (nums[mid] == nums[mid + 1]) {
                high = mid - 1;
            } else {
                return nums[mid];
            }
        }
        return nums[low];
    }
};