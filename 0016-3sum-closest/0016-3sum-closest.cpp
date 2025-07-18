// Sorting + 2-pointers approach
// TC: O(n^2)
// SC: O(logn)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        ranges::sort(nums);

        // [-4,-1,1,2]
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            // apply 2 pointers
            int left = i + 1, right = n - 1;
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                int sumDiff = currSum - target;

                // store sum with minimum difference
                if (std::abs(sumDiff) < std::abs(closestSum - target)) {
                    closestSum = currSum;
                } 

                // check for closest difference to the target
                if (sumDiff < 0) {
                    left++;   // go for more positive numbers
                }
                else if (sumDiff > 0) {
                    right--;  
                }
                // early termination when exact match
                else {
                    return closestSum;
                } 
            }
        }

        return closestSum;
    }
};