// One-time Traversal approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        // since we are concerned with number of consecutive letters
        // using hashmap will fail
        size_t n = word.length();
        int maxStrings = 1;

        for (int i = 0; i < n - 1; i++) {
            if (word[i] == word[i + 1]) {
                maxStrings++;
            }
        }

        return maxStrings;
    }
};