// Prefix-Suffix Approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // not possible with less than 3 bars

        stack<int> stL, stR;
        vector<int> leftMax(n, 0), rightMax(n, 0);  // boundaries for trapping water

        // Construct leftMax array
        for (int i = 0; i < n; i++) {
            int bar = height[i];
            if (stL.empty()) {
                leftMax[i] = bar;
            } 
            else {
                leftMax[i] = max(leftMax[i - 1], bar);
            }
            stL.push(bar);
        }

        // Construct rightMax array
        for (int i = n - 1; i >= 0; i--) {
            int bar = height[i];
            if (stR.empty()) {
                rightMax[i] = bar;
            } 
            else {
                rightMax[i] = max(rightMax[i + 1], bar);
            }
            stR.push(bar);
        }

        // Calculate trapped water
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int waterHeight = min(leftMax[i], rightMax[i]) - height[i];
            if (waterHeight > 0) {
                totalWater += waterHeight;
            }
        }
        return totalWater;
    }
};
