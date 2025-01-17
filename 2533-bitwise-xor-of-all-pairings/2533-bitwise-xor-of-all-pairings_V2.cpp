// HashMap Approach
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, long> freq; // map to store count of each number
        
        for (int i: nums1) {
            freq[i] += m;  // Each element appears 'm' times in final result
        }
        for (int j: nums2) {
            freq[j] += n;
        }

        int res = 0;
        for (auto& [num, count] : freq) {
            // EVEN: (a ^ a) ^ (a ^ a) = 0
            // ODD:  (a ^ a) ^  a      = a 
            if (count % 2 == 1) {
                res ^= num;  
            }
        }
        return res;
    }
};
