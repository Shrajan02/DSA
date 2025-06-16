// Kadane like Greedy approach
// Best time to buy & sell stock problem
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1, minVal = nums[0];
        
        for (int i = 1; i < n; i++) {
            // condition: nums[i] < nums[j]
            maxDiff = max((nums[i] > minVal) ? nums[i] - minVal : maxDiff, maxDiff);
            minVal = min(nums[i], minVal);
        }

        return maxDiff;
    }
};