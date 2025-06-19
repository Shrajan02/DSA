// Sorting + Greedy approach
// TC: O(n*log n)
// SC: O(log n)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        
        ranges::sort(nums); // [1, 2, 3, 5, 6]

        int mini = nums[0], maxi = nums[0];
        for (int i = 1; i < n; i++) {
            maxi = nums[i];
            if (maxi - mini > k) {
                mini = maxi;
                count++;
            }
        }

        return count;
    }
};