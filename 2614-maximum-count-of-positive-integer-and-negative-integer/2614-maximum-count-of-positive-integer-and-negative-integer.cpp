// Brute Force approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for (int num: nums) {
            if (num > 0) {
                pos++;
            }
            else if (num < 0) {
                neg++;
            }
        }
        return max(pos, neg);
    }
};