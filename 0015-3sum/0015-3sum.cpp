// Sorting + 2-pointers approach
// TC: O(n^2) 
// SC: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());  
        for (int i = 0; i < n; i++) {
            // skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // apply 2-pointers
            int j = i + 1; // left ptr
            int k = n - 1; // right ptr
            while (j < k) {
                int triplet = nums[i] + nums[j] + nums[k];
                if (triplet > 0) {
                    k--;
                } 
                else if (triplet < 0) {
                    j++;
                } 
                else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;  // skip duplicates for j
                    while (j < k && nums[k] == nums[k - 1]) k--;  // skip duplicates for k
                    j++;
                    k--;
                }
            }
        }
        return result;
    }
};