class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini = INT_MAX;
        int original = 0;
        for (auto i : nums) {
            int val = abs(i);
            if (val < mini || (val == mini && i > original)) {
                mini = val;
                original = i;
            }
        }

        return original;
    }
};