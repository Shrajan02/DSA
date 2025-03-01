// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Apply operation
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Move all zeroes to the end
        int count = 0;  // pointer to track next non-zero element
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[count++]);
            }
        }

        return nums;
    }
};