// 2 pointer approach
// TC: O(n)
// TC: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int left = 0, right = n - 1;  // 2 pointers
        while (left < right) {
            int mini = min(height[left], height[right]);
            int currentArea = mini * (right - left);
            maxArea = max(currentArea, maxArea);  
            if (height[left] <= height[right]) {
                left++;
            } 
            else {
                right--;
            }
        }
        return maxArea;  
    }
};
