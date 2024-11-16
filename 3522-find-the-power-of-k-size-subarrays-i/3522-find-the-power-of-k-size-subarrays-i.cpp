class Solution {
public:
    int power(vector<int>& nums, int start, int k) {
        // Check for sorted consecutive, then max 
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] != nums[i+1] - 1)
                return -1;
        }
        return nums[start + k - 1];
    }
    
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results(n - k + 1);
        for (int i = 0; i <= n-k; i++) {
            results[i] = power(nums, i, k);
        }
        return results;
    }
};