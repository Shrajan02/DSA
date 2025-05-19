// Basic Maths Approach
// TC: O(1)
// SC: O(1)
class Solution {
public:
    string triangleType(vector<int>& nums) {
        // TRIANGLE INEQUALITY THEOREM: Sum of any two sides must be greater than the third
        sort(nums.begin(), nums.end());  // After sorting, sum of the two smallest sides must be greater than the largest to form a valid triangle
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        else if (nums[0] == nums[2]) {
            return "equilateral";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        else {
            return "scalene";
        }
    }
};