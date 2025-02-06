// Product Frequency HashMap Approach
// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = nums[i] * nums[j];
                if (mp.count(k)) {
                    count += mp[k] * 8;
                }
                mp[k]++;
            }
        }
        return count;
    }
};