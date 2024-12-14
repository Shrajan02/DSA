class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int count = 0, n = nums.size();
        int first = 0, second = 1;
        int score = nums[first] + nums[second];

        while (first < n && second < n) {
            if (nums[first] + nums[second] != score) {
                break;
            }
            count++;
            first += 2;
            second += 2;
        }
        return count;
    }
};