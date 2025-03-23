// Hash set approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // edge case

        unordered_set<int> hashSet(nums.begin(), nums.end());
        int maxLen = 1;
        for (int num: hashSet) {
            // check if current number is start of a consecutive sequence
            if (hashSet.find(num - 1) == hashSet.end()) {
                int currLen = 1;  // reset the counter
                while (hashSet.find(num + currLen) != hashSet.end()) {
                    currLen++;
                }
                maxLen = max(currLen, maxLen);
            } 
        }
        return maxLen;
    }
};