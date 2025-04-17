// Brute-Force approach
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int countPairs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    countPairs++;
                }
            }
        }
        return countPairs;
    }
};