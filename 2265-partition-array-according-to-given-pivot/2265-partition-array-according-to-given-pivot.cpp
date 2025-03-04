// 2-pointer approach (1 pass)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int lessPiv = 0;        // next index of elements < pivot
        int lessEqualPiv = 0;   // next index of elements <= pivot
        int greaterPiv = n - 1; // next (from right) index of elements > pivot

        // l from start, r from end
        for (int l = 0, r = n - 1; l < n; l++, r--) {
            if (nums[l] <= pivot) {
                ans[lessEqualPiv] = pivot;
                lessEqualPiv++;
                ans[lessPiv] = nums[l];
                if (nums[l] != pivot) {
                    lessPiv++;
                }
            }
            if (nums[r] > pivot) {
                ans[greaterPiv--] = nums[r];
            }
        }

        return ans;
    }
};
