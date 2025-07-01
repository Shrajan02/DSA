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

        int consecutive = 1;
        for (int i = 1; i < n; i++) {
            char key = word[i], prevKey = word[i - 1];
            if (key != prevKey) {
                if (consecutive > 1) {
                    maxStrings += (consecutive - 1);  // add (k-1) for k consecutive same chars
                }
                consecutive = 1;
            } 
            else {
                consecutive++;
            }
        }
        if (consecutive > 1) {
            maxStrings += (consecutive - 1);
        }

        return maxStrings;
    }
};