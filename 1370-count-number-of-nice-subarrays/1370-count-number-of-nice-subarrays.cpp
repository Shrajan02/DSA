// Modified Sliding Window approach
// TC: O(n)
// SC: O(1)
class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();

        int atMostCount = 0;
        int start = 0, oddCount = 0;
        for (int end = 0; end < n; end++) {
            if (nums[end] % 2 == 1) {
                oddCount++;
            }
            while (oddCount > k) {
                if (nums[start] % 2 == 1) {
                    oddCount--;
                }
                start++;
            }
            atMostCount += (end - start + 1);
        }
        return atMostCount;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int countNice = atMost(nums, k) - atMost(nums, k - 1);
        return countNice;
    }
};