class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while (k--) {
            int minIndex = 0;
            for (int i = 0; i < n; i++) {
                if (nums[minIndex] > nums[i]) {
                    minIndex = i;
                }
            }
            nums[minIndex] *= multiplier;
        } 
        return nums;
    }
};