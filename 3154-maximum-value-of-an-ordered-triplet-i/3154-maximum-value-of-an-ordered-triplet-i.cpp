// Brute force enumeration approach
// TC: O(n^3) 
// SC: O(1)
#define ll long long 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll currValue = 0, maxValue = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    currValue = static_cast<ll>(nums[i] - nums[j]) * nums[k];
                    maxValue = max(currValue, maxValue);
                }
            }
        }
        return maxValue;
    }
};