// Dynamic Sliding Window approach
// TC: O(n)
// SC: O(1)

#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        ll count = 0;

        int start = -1;  // last invalid element
        int mini = -1;   // last minK encountered
        int maxi = -1;  // last maxK encountered
        // if a number outside the range [minK, maxK] appears, then window resets on invalid elements
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                start = i;
            if (nums[i] == maxK)
                maxi = i;
            if (nums[i] == minK)
                mini = i;
            ll valid = max(0LL, (ll)(min(mini, maxi) - start));
            count += valid;
        }

        return count;
    }
};