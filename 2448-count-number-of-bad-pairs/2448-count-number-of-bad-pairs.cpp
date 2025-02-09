// TC: O(n)
// SC: O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;  // {i - nums[i] -> count}
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int diff = i - nums[i]; // (position - value)
            goodPairs += mp[diff];
            mp[diff]++;
        }
        long long badPairs = 1LL * n * (n - 1) / 2 - goodPairs;
        return badPairs;
    }
};