// Recursion Backtracking approach
// TC: O(2^n)
// SC: O(n)
class Solution {
private:
    int generateMaxORSubsets(vector<int>& nums, int i, int currOR, int maxOR) {
        if (i == nums.size()) {
            return (currOR == maxOR) ? 1 : 0; 
        }

        int countWithout = generateMaxORSubsets(nums, i + 1, currOR, maxOR);   // skip
        
        // calculate bitwise OR with current element
        currOR |= nums[i];
        int countWith = generateMaxORSubsets(nums, i + 1, currOR, maxOR);  // pick

        return (countWithout + countWith);        
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        // bitwise OR of all elements gives the max possible OR 
        int maxOR = 0;
        for (int num: nums) {
            maxOR |= num;
        }

        int i = 0, currOR = 0;
        int count = generateMaxORSubsets(nums, i, currOR, maxOR);
        return count;
    }
};