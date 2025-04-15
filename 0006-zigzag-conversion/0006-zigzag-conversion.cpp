// Simulation approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string res;
        int n = s.length();
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += cycleLen) {
                res.push_back(s[j]);

                // add diagonal character
                if (i > 0 && i < numRows - 1 && j + cycleLen - 2 * i < n) {
                    res.push_back(s[j + cycleLen - 2 * i]);
                }
            }
        }
        return res;
    }
};
