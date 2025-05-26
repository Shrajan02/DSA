// In Place Transformation approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // Main problem: How do we keep both the old value and new value in the same array ?!
        // Solution: Use Base Encoding
        int n = nums.size();

        // encode both old & new values in the same slot
        for (int i = 0; i < n; i++) {
            int oldVal = nums[i];  
            int newVal = nums[nums[i]];
            nums[i] = oldVal + (newVal % n) * n;  // nums[i] = a + b * n
        }

        // extract only the new value
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }
        return nums;
    }
};