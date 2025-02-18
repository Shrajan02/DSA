class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long range = 0;
        for (int i = 0; i < n; i++) {
            int large = nums[i];
            int small = large;
            for (int j = i; j < n; j++) {
                large = max(large, nums[j]);
                small = min(small, nums[j]);
                range += (large - small);
            }
        }
        return range;
    }
};