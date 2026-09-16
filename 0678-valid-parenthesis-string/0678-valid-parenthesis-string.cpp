// greedy 2-pointers approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                open++;
            }
            else {
                open--;
            }

            if (s[n - i - 1] == ')' || s[n - i - 1] == '*') {
                close++;
            }
            else {
                close--;
            }

            if (open < 0 || close < 0) {
                return false;
            }
        }

        return true;
    }
};