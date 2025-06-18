// Greedy + Sorting approach
// TC: O(n*log(n))
// SC: O(log(n))
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i += 3) {
            // any two elements after sorting becomes 1st & 3rd element
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        
        return res;
    }
};