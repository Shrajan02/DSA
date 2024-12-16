class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while (k > 0) {
            int mini = INT_MAX, index = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (mini >= nums[i]) {
                    mini = nums[i];
                    index = i;
                }
            }
            nums[index] *= multiplier;
            k--;
        } 
        return nums;
    }
};