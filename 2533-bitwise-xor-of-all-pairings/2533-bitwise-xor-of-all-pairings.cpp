// Space-optimized Bit Manipulation
// TC: O(n+m)
// SC: O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int first = 0, second = 0;

        for (int i: nums1) {
            first ^= i;
        }
        for (int j: nums2) {
            second ^= j;
        }

        int res = 0;
        if (m % 2 != 0) {
            res ^= first;
        }
        if (n % 2 != 0) {
            res ^= second;
        }

        return res;
    }
};