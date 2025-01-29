// TC: O(n)
// SC: O(min(n, k))
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashMap;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (hashMap.find(val) != hashMap.end() && i - hashMap[val] <= k) {
                return true;
            }
            hashMap[val] = i;
        }
        return false;
    }
};