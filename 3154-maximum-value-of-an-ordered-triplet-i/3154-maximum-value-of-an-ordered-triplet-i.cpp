#define ll long long 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll current = 0, maxi = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    current = (ll)(nums[i] - nums[j]) * nums[k];
                    maxi = max(current, maxi);
                }
            }
        }
        return maxi;
    }
};