// Hash Table approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // build frequency map
        vector<int> freq(501, 0);
        for (int num: nums) {
            freq[num]++;
        }
        // check for even appearings
        for (int i = 1; i <= 500; i++) {
            if (freq[i] % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};