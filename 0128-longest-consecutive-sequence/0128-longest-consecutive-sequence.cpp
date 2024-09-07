class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        sort (nums.begin(), nums.end());
        
        int start = INT_MIN, maxi = 1, len = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] - 1 == start) 
                len++;
            else if (nums[i] - 0 == start)
                continue;
            else
                len = 1; 
            start = nums[i];
            maxi = max(maxi, len);
        }
        return maxi;
    }
};