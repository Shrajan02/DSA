// Monotonic stack approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack; // (index, height)

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                pair<int, int> top = stack.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height * (i - index));
                start = index;
                stack.pop();
            }
            stack.push({ start, heights[i] });
        }

        while (!stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            maxArea = max(maxArea, height * (int)(heights.size() - index));
            stack.pop();
        }
        return maxArea;
    }
};