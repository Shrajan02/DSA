// 2-pointers approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;

        for (char bracket: s) {
            if (bracket == '(') {
                open++;
            }
            // when bracket is ')'
            else {
                if (open == 0) {
                    close++;
                }
                else {
                    open--;
                }
            }
        }

        return (open + close);
    }
};