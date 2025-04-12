// Prefix-Suffix Hashing approach
// TC: O(n^2)
// SC: O(n)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        int countQuads = 0;

        for (int b = 1; b < n; b++) {
            // a + b
            for (int a = 0; a < b; a++) {
                freqMap[nums[a] + nums[b]]++;
            }

            // d - c
            int c = b + 1;
            for (int d = b + 2; d < n; d++) {
                countQuads += freqMap[nums[d] - nums[c]];
            }
        }
        return countQuads;
    }
};