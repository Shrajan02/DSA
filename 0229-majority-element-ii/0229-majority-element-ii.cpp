// Extended Boyer Moore's Majority Voting Algorithm
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // atmost only 2 elements can appear more than n/3 times
        int n = nums.size();
        int num1 = 0, num2 = 0;   // tracks potential candidates
        int count1 = 0, count2 = 0;  

        // candidate selection
        for (int val: nums) {
            if (val == num1) count1++;
            else if (val == num2) count2++;
            else if (count1 == 0) {
                num1 = val;
                count1 = 1;
            }
            else if (count2 == 0) {
                num2 = val;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // verification
        count1 = 0, count2 = 0;
        for (int val: nums) {
            if (val == num1) {
                count1++;
            }
            else if (val == num2) {
                count2++;
            }
        }

        if (count1 > n/3 && count2 > n/3) {
            return {num1, num2};
        }
        else if (count1 > n/3) {
            return {num1};
        }
        else if (count2 > n/3) {
            return {num2};
        }
        return {};
    }
};