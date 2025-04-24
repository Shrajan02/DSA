// Brute force approach
// TC: O(n^2)
// SC: O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique(nums.begin(), nums.end());
        int totalUnique = unique.size(), count = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> curr;
            for (int j = i; j < n; j++) {
                curr.insert(nums[j]);
                if (curr.size() == totalUnique) {
                    count++;
                }
            }
        }
        return count;
    }
};
