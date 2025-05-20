// Difference Array approach 
// when same operation is performed within a range multiple times
// TC: O(n + m)
// SC: O(n)
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // create difference array
        vector<int> diffArray(n + 1, 0);
        for (const auto& query: queries) {
            int left = query[0], right = query[1];
            diffArray[left]++;
            diffArray[right + 1]--;
        }

        int count = 0;  // total decrements possible at nums[i]
        for (int i = 0; i < n; i++) {
            count += diffArray[i];
            if (nums[i] > count) {
                return false;
            }
        }
        return true;
    }
};