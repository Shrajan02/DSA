// Sliding Window [atmost] approach
// TC: O(n)
// SC: O(1)
class Solution {
private:
    // count subarrays with sum AT MOST the given goal
    int atMost(vector<int>& nums, int goal){
        int n = nums.size();
        int start = 0, currentSum = 0, count = 0; 

        for (int end = 0; end < n; end++) {
            currentSum += nums[end];
            // shrink window if sum exceeds goal
            while (start <= end && currentSum > goal) {
                currentSum -= nums[start];
                start++;
            }
            count += (end - start + 1);
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // atMost(2) - atMost(1)
        int totalCount = atMost(nums, goal) - atMost(nums, goal - 1);
        return totalCount;
    }
};