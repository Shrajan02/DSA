// 2-pointers approach
// TC: O(N)
// SC: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // find the smallest element larger than nums[pivot] from the right
        if (pivot != -1) {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    std::swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // reverse elements after the pivot
        std::reverse(nums.begin() + pivot + 1, nums.end());
    }
};
