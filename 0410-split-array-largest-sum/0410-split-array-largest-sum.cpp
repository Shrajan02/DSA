// Book Allocation Problem 

class Solution {
public:
    bool minSplit(vector<int> nums, int maxAllowedSum, int maxSplits) {
        int split = 1, currSum = 0;  // Initially, the 1st split has no elements: zero sum
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxAllowedSum) {
                return false; // If any element is greater than sum, impossible 
            }
            if (currSum + nums[i] <= maxAllowedSum) {
                currSum += nums[i];
            }
            else {
                split++;
                currSum = nums[i];
            }
        }

        return (split <= maxSplits);
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = *max_element(nums.begin(), nums.end());

        // Binary Search Approach: O(n * log(sum - maxi))
        int low = maxi, high = sum, maxSum = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool possible = minSplit(nums, mid, k);
            if (possible) {
                maxSum = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return maxSum;
    }
};