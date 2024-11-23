class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int num : nums) {
            hashMap[num]++;
            if (hashMap[num] > 1) { 
                return true;
            }
        }
        return false;
    }
};
