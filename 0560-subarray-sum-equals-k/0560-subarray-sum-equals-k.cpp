class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, preSum = 0;
        int n = nums.size();
        map<int, int> hash = {{0, 1}}; // <preSum, count>

        for (auto i : nums) {
            preSum += i; 
        
            // Check if (preSum - k) exists in hashmap
            int rem = preSum - k;
            count += hash[rem]; 
            hash[preSum]++; // Updating hashmap
        }
        return count;
    }
};