// Greedy approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long maxElement = 0, maxDiff = 0, maxTriplet = 0;
        for (int i = 0; i < n; i++) {
            maxTriplet = max(maxDiff * nums[i], maxTriplet);  // nums[k]
            maxDiff = max(maxElement - nums[i], maxDiff);     // nums[j]
            maxElement = max((long)nums[i], maxElement);      // nums[i]
        }
        return maxTriplet;
    }
};