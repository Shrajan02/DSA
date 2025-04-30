// Math Logarithm approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for (int num: nums) {
            int digitCount = (int)(log10(num) + 1);  // log10(0) = undefined (edge case)
            if (digitCount % 2 == 0) {
                evenCount++;
            }
        }
        return evenCount;
    }
};