// Binary Search approach
// TC: O(log(m).(n+m))
// SC: O(n)
class Solution {
private:
    bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size(), sum = 0;
        vector<int> differenceArray(n + 1);

        for (int i = 0; i < k; i++) {
            int left = queries[i][0], right = queries[i][1], val = queries[i][2];
            // process start and end of range
            differenceArray[left] += val;
            differenceArray[right + 1] -= val;
        }

        // check if zero array can be formed
        for (int num = 0; num < n; num++) {
            sum += differenceArray[num];
            if (sum < nums[num]) {
                return false;
            }
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int left = 0, right = queries.size();

        // zero array not formed after all queries are processed
        if (!canFormZeroArray(nums, queries, right)) {
            return -1;
        }

        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            bool possible = canFormZeroArray(nums, queries, middle);
            if (possible) {
                right = middle - 1;
            } 
            else {
                left = middle + 1;
            }
        }
        return left;
    }
};