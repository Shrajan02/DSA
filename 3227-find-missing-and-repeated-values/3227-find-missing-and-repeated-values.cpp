// HashMap Improved approach
// TC: O(n^2)
// SC: O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2, 0);

        // construct hash table & calculate sum of elements
        unordered_map<int, int> hashMap;
        int currSum = 0;
        for (auto& row : grid) {
            for (int val : row) {
                // check for duplicate
                if (hashMap.count(val)) {
                    ans[0] = val;
                }
                else {
                    hashMap[val]++;
                    currSum += val;
                }
            }
        }

        int total = n * n;
        int expectedSum = (total * (total + 1)) / 2;  // sum of elements from 1 to n^2
        ans[1] = expectedSum - currSum;  // missing value

        return ans;
    }
};