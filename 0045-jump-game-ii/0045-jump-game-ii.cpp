// greedy approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int minJumps = 0, maxReach = 0, jumpEnd = 0;
        for (int i = 0; i < n - 1; i++) {
            maxReach = std::max(maxReach, i + nums[i]);
            if (i == jumpEnd) {
                minJumps++;
                jumpEnd = maxReach;
            }
        }

        return minJumps;
    }
};