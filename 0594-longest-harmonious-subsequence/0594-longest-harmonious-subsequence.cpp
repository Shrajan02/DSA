// Hash Table approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // {1:1, 2:3, 3:2, 5:1, 7:1}
        for (auto& [num, cnt]: freq) {
            if (freq.count(num + 1)) {
                maxLength = max(cnt + freq[num + 1], maxLength);  // [min count + max count]
            }
        }

        return maxLength;
    }
};
