class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());       // Reverse complete array
        reverse(nums.begin(), nums.begin() + k); // Reverse first 'k' elements
        reverse(nums.begin() + k, nums.end());   // Reverse last 'n-k' elements
    }
};
