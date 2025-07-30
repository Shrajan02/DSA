// Bitwise Greedy + Sliding Window approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> setBitIndex(32, -1);  // [0, 10^9] can contain upto 32 binary bits (0 -31)
        // setBitIndex[j] = i, latest index where jth bit can be set via nums[i]

        for (int i = n - 1; i >= 0; i--) {
            int endIdx = i;
            // j -> iterates over each bit position
            for (int j = 0; j < 32; j++) {
                // jth bit not set
                if (!(nums[i] & (1 << j))) { 
                    if (setBitIndex[j] != -1) {
                        endIdx = std::max(setBitIndex[j], endIdx);  // choose farthest index where jth bit was last seen
                    }
                }
                // jth bit set
                else {
                    setBitIndex[j] = i;  // choose current index since it is smallest  
                }
            }
            result[i] = endIdx - i + 1;   
        }

        return result;
    }
};