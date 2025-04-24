// Sliding Window + Hash Table approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        // counting distinct elements
        unordered_set<int> unique(nums.begin(), nums.end());
        int totalUnique = unique.size();

        int count = 0, start = 0;
        unordered_map <int, int> freqMap;  // {num, count}
        for (int end = 0; end < n; end++) {
            freqMap[nums[end]]++;
            while (freqMap.size() == totalUnique) {
                count += (n - end);
                freqMap[nums[start]]--;
                if (freqMap[nums[start]] == 0) {
                    freqMap.erase(nums[start]);
                }
                start++;
            }
        }
        return count;
    }
};
