class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();

        vector<pair<int, int>> sorted(n);
        for (int i = 0; i < n; i++) {
            sorted[i] = make_pair(nums[i], i);
        }
        sort(sorted.begin(), sorted.end());

        vector<bool> marker(n, false);
        for (int i = 0; i < n; i++) {
            int num = sorted[i].first, index = sorted[i].second;
            if (!marker[index]) {
                score += num;
                marker[index] = true;
                // mark adjacent elements if they exist
                if (index - 1 >= 0) 
                    marker[index - 1] = true;
                if (index + 1 < n) 
                    marker[index + 1] = true;
            }
        }
        return score;
    }
};