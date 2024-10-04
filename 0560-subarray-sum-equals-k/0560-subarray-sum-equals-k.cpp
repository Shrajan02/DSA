class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0, preSum = 0;
        int n = nums.size();
        map<int, int> hash; 

        hash[0] = 1; // Edge case: here subarray starts from index 0

        for (int i = 0; i < n; i++) {
            preSum += nums[i]; // Update prefix sum

            // Check if (preSum - k) exists in the map
            if (hash.find(preSum - k) != hash.end()) {
                count += hash[preSum - k]; // Add the frequency of (preSum - k)
            }

            // Store the frequency of the current prefix sum
            hash[preSum]++;
        }

        return count;
    }
};