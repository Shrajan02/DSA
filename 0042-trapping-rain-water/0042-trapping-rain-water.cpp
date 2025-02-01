// Optimized 2-pointer Approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // not possible with less than 3 bars

        int totalWater = 0;
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                }
                else {
                    totalWater += maxLeft - height[left];
                }
                left++;
            }
            else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                }
                else {
                    totalWater += maxRight - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};
