// Sorting + Set + 2-pointers approach
// TC: O(n^2) 
// SC: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> hashSet;  // handles duplicate values 

        sort(nums.begin(), nums.end());  
        for (int i = 0; i < n; i++) {
            // apply 2-pointers
            int j = i + 1; // left ptr
            int k = n - 1; // right ptr
            while (j < k) {
                int triplet = nums[i] + nums[j] + nums[k];
                if (triplet > 0) {
                    k--;
                } 
                else if (triplet < 0) {
                    j++;
                } 
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    hashSet.insert(temp);
                    j++;
                    k--;
                }
            }
        }

        vector<vector<int>> result;
        for (auto key: hashSet) {
            result.push_back(key);
        }
        return result;
    }
};