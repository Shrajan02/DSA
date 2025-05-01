// Greedy approach
// TC: O(n)
// SC: O(1)
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll maxElement = 0, maxDiff = 0, maxTriplet = 0;
        for (int i = 0; i < n; i++) {
            maxTriplet = max(maxDiff * nums[i], maxTriplet);
            maxDiff = max(maxElement - nums[i], maxDiff); 
            maxElement = max((ll)nums[i], maxElement);    
        }
        return maxTriplet;
    }
};