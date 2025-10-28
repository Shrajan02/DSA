// Prefix Sum approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        // build prefix sum 
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }

        int valid_selections = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // check left & right subarrays
                int left = prefix_sum[i];                
                int right = prefix_sum[n] - prefix_sum[i + 1]; 
                if (left == right) {
                    valid_selections += 2;
                } 
                else if (abs(left - right) == 1) {
                    valid_selections++;
                }     
            }
        }

        return valid_selections;
    }
};
