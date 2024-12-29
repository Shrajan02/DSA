class Solution {
private:
    void generateSubsets(vector<vector<int>>& result, const vector<int>& candidates, vector<int> current, int target, int start) {
        if (target < 0) {
            return; 
        }
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            current.push_back(candidates[i]); // pick
            generateSubsets(result, candidates, current, target - candidates[i], i + 1); 
            current.pop_back(); // backtrack (skip)
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sorting to handle duplicates
        generateSubsets(result, candidates, current, target, 0);
        return result;
    }
};
