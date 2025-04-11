// Prefix-Suffix approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int maxProduct = INT_MIN;

        for (int i = 0; i < n; i++) {
            // even number of negatives → +ve product
            // odd number of negatives → -ve product
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxProduct = max(maxProduct, max(prefix, suffix));
        }
        return maxProduct;
    }
};