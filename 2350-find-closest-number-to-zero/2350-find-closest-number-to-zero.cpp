class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int close = nums[0];
        int absClose = abs(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i]) < absClose ||
                (abs(nums[i]) == absClose && nums[i] > close)) {
                absClose = abs(nums[i]);
                close = nums[i];
            }
        }
        return close;
    }
};