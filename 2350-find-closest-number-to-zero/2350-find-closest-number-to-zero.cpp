class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = INT_MAX;
        for (auto i : nums) {
            if (abs(i) < abs(res)) {
                res = i;
            } else if (abs(i) == abs(res)) {
                res = max(res, i);
            }
        }
        return res;
    }
};