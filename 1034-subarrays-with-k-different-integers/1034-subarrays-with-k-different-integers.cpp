// Modified Sliding Window + Hash Map approach
// TC: O(n)
// SC: O(n)
class Solution {
private:
    int atMostDiff(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> freq;
        int left = 0;
        for (int right = 0; right < n; right++) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exactly k = atMost(k) - atMost(k - 1)
        // exactly k = atLeast(k) - atLeast(k + 1)
        int countGood = atMostDiff(nums, k) - atMostDiff(nums, k - 1);
        return countGood;
    }
};