// Monotonic stack approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st;  // (index, height)

        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                pair<int, int> top = st.top();
                int index = top.first, height = top.second;
                maxArea = max(height * (i - index), maxArea);
                start = index;
                st.pop();
            }
            st.push({start, heights[i]});
        }

        // remaining bars
        while (!st.empty()) {
            int index = st.top().first, height = st.top().second;
            maxArea = max(maxArea, height * (int)(n - index));
            st.pop();
        }
        return maxArea;
    }
};
