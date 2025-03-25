// Sliding Window approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, minLen = INT_MAX;
        int left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            // dynamic window
            while (sum >= target) {
                minLen = min(right - left + 1, minLen);
                sum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};