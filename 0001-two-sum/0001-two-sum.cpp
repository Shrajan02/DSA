class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        int n = nums.size();
        // 2-pass Hash Table
        for (int i = 0; i < n; i++) {
            hashMap[nums[i]] = i;
        }

        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if(hashMap.find(complement) != hashMap.end() && hashMap[complement] != i)
                return {hashMap[complement], i};
        }
        return {};
    }
};