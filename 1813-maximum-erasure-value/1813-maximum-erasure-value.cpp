// Sliding Window + Hash Set approach
// TC: O(n)
// SC: O(unique)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> unique; 

        int max_score = 0, curr_score = 0;
        int start = 0;
        for (int end = 0; end < n; end++) {
            int curr = nums[end];
            // removing duplicate element
            while (unique.count(curr) > 0) {
                unique.erase(nums[start]);
                curr_score -= nums[start];
                start++;
            }
            // add current element
            curr_score += curr;
            unique.insert(curr);
            
            max_score = std::max(curr_score, max_score);
        }

        return max_score;
    }
};