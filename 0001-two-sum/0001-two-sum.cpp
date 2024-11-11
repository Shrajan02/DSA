class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(hashmap.find(complement) != hashmap.end()) {
                return {hashmap[complement], i};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};