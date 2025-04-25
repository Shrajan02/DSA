// Prefix Sum + Hash Table approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // construct prefix sum array
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        // For any subarray nums[i...j], sum: prefix[j] - prefix[i - 1]
        // (prefix[j] - prefix[i - 1]) % k == 0
        // (prefix[j] % k) == (prefix[i - 1] % k)
        // (prefix[i] % k) == (prefix[j] % k)
        unordered_map<int, int> modCount; // {prefix[i] % k, count}
        modCount[0] = 1;  // base case
        for (int i = 0; i < n; i++) {
            int mod = ((prefix[i] % k) + k) % k; // handle negative mods
            count += modCount[mod]; 
            modCount[mod]++; 
        }

        return count;
    }
};