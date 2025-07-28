// Two-pointers approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        int prev = 0;
        for (int i = 1; i < n - 1; i++) {
            int curr = nums[i];
            if (curr != nums[i + 1]) { // skipping duplicates
                if ((curr > nums[prev] && curr > nums[i + 1]) || (curr < nums[prev] && curr < nums[i + 1])) {
                    count++;
                }
                prev = i;
            }
        }

        return count;
    }
};