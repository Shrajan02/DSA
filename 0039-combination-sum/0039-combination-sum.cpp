// TC: O(2^n)
// SC: O(n)
class Solution {
private:
    void calculateSubsets(vector<vector<int>>& result, const vector<int>& arr, vector<int>& current, int target, int sum, int i) {
        if (sum > target) {
            return;  // stop recursion
        }
        if (sum == target) {
            result.push_back(current);  // add current combination
            return;
        }

        for (int j = i; j < arr.size(); j++) {
            current.push_back(arr[j]); // duplicate pick
            calculateSubsets(result, arr, current, target, sum + arr[j], j); // recursion with same 'j'
            current.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        calculateSubsets(result, candidates, current, target, 0, 0);
        return result;
    }
};
