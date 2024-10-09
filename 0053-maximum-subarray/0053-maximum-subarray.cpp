class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm: O(n)
        int currSum = 0, maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];   // Add element to the current subarray sum
            maxSum = max(maxSum, currSum);   // Update maximum sum
            // Reset current sum to 0 when sum is negative
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};