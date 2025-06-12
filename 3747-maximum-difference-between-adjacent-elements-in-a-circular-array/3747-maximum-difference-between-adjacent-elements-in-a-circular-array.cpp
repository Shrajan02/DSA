// Brute-force traversal approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            int diff = abs(nums[i] - nums[i + 1]);
            maxDiff = max(diff, maxDiff);
        }
        
        maxDiff = max(abs(nums[0] - nums[n - 1]), maxDiff);   // circular array property
        return maxDiff;
    }
};