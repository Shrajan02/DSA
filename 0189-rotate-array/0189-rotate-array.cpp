class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.end() - k, nums.end());   // Reverse last 'k' elements
        reverse(nums.begin(), nums.end() - k); // Reverse first 'n-k' elements
        reverse(nums.begin(), nums.end());     // Reverse complete array
    }
};