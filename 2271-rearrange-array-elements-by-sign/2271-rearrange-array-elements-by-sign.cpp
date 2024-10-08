class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // 2-pointer approach
        int i = 0, j = 1, n = nums.size(); 
        vector<int> result(n, 0);
        for (auto num: nums) {
            if(num > 0) {
                result[i] = num;
                i += 2;
            }
            else {
                result[j] = num;
                j += 2;
            }
        }
        return result;
    }
};