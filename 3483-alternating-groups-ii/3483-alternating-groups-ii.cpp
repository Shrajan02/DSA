// Sliding Window approach
// TC: O(n)
// SC: O(k)
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // extend array to handle circular sequences
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }

        int n = colors.size();
        int result = 0;
        int start = 0, end = 1;  // bounds of the sliding window
        while (end < n) {
            if (colors[end] == colors[end - 1]) {
                // if pattern breaks, reset window 
                start = end;
                end++;
                continue;
            }

            end++;  // expand window to the end
            if (end - start < k) continue;  // skip counting sequence

            // shrink window from the start 
            result++;
            start++;
        }

        return result;
    }
};