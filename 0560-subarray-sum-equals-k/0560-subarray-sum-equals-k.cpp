class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, preSum = 0;
        int n = nums.size();
        map<int, int> hash;  // <preSum, count>

        hash[0] = 1; // setting 0 in the hashmap
        for (int i = 0; i < n; i++) {
            preSum += nums[i]; 
            
            // Check if (preSum - k) exists in hashmap
            int rem = preSum - k;
            count += hash[rem]; 
            
            hash[preSum]++; // Updating hashmap
        }
        return count;
    }
};
