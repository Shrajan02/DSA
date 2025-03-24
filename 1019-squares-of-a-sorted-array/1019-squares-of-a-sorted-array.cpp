// 2-pointer approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int i = 0, j = n - 1; 
        for (int idx = n - 1; idx >= 0; idx--) {
            if (abs(nums[i]) <= abs(nums[j])) {
                result[idx] = nums[j] * nums[j];
                j--;
            }
            else {
                result[idx] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};