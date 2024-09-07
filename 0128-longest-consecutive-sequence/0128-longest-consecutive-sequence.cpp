class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        if (nums.size() == 0)
            return 0;
        int start = nums[0], maxi = 1, len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - start == 1) 
                len++;
            else if (nums[i] - start == 0)
                continue;
            else
                len = 1; 
            start = nums[i];
            maxi = max(maxi, len);
        }
        return maxi;
    }
};