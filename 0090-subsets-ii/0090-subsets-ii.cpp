class Solution {
private:
    void generatePowerSet(vector<vector<int>>& power, vector<int>& current, const vector<int>& nums, int start) {
        power.push_back(current);
    
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) // ignore duplicates
                continue;
            current.push_back(nums[i]); // pick
            generatePowerSet(power, current, nums, i + 1);
            current.pop_back(); // skip
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // sorting to handle duplicates
        vector<vector<int>> power;
        vector<int> current;
        generatePowerSet(power, current, nums, 0);
        return power;
    }
};
