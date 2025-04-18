// Hash Map approach
// TC: O(n^2) 
// SC: O(n)
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int countPairs = 0;
        unordered_map<int, vector<int>> freqMap;  // {value, indices where value appeared}

        for (int curr = 0; curr < n; curr++) {
            // check all previous indices with same value
            for (int prev : freqMap[nums[curr]]) {
                if ((curr * prev) % k == 0) {
                    countPairs++;
                }
            }
            freqMap[nums[curr]].push_back(curr);
        }
        return countPairs;
    }
};
