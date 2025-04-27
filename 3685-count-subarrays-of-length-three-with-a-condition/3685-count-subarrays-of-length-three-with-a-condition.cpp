// One-Time Traversal
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int sumCheck = 2 * (nums[i] + nums[i + 2]);
            if (sumCheck == nums[i + 1]) {
                count++;
            }
        }

        return count;
    }
};