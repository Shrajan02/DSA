// Brute Force approach
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        for (int i = 0; i < n; i++) {
            int product = 1;
            for (int j = i; j < n; j++) {
                product *= nums[j];
                maxProduct = max(product, maxProduct);
            }
        }
        return maxProduct;
    }
};