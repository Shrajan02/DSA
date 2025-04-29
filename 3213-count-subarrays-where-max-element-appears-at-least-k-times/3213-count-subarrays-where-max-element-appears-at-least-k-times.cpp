// Sliding Window approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxElement = INT_MIN;
        for (int num: nums) {
            maxElement = max(num, maxElement);
        }

        long long count = 0, left = 0;
        int maxCount = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == maxElement) {
                maxCount++;
            }

            while (maxCount == k) {
                if (nums[left] == maxElement) {
                    maxCount--;
                }
                left++;
            }
            count += left;
        }
        return count;
    }
};