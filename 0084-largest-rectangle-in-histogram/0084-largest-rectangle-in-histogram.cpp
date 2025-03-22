// Monotonic stack approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> stack;  // (index, height)

        for (int i = 0; i < n; i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                pair<int, int> top = stack.top();
                int index = top.first, height = top.second;
                maxArea = max(height * (i - index), maxArea);
                start = index;
                stack.pop();
            }
            stack.push({start, heights[i]});
        }

        // remaining bars
        while (!stack.empty()) {
            int index = stack.top().first, height = stack.top().second;
            maxArea = max(maxArea, height * (int)(n - index));
            stack.pop();
        }
        return maxArea;
    }
};