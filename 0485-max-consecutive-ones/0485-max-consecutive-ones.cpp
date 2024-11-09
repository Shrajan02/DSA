class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0, count = 0;
        for (auto i: nums) {
            if (i == 1) {
                count++;
                max_count = max(count, max_count);
            }
            else {
                count = 0;
            }
        }
        return max_count;
    }
};