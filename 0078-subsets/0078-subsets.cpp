class Solution {
private:
    void generateSubset(vector<vector<int>>& result, vector<int> current, const vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }

        generateSubset(result, current, nums, i + 1);  // skip

        current.push_back(nums[i]);
        generateSubset(result, current, nums, i + 1); // pick
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubset(result, current, nums, 0);
        return result;
    }
};