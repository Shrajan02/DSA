// Stack-like Approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string clearDigits(string s) {
        string res = "";  // acts like stack
        for (const char &ch: s) {
            if (isdigit(ch) && !res.empty()) {
                res.pop_back();
            }
            else {
                res += ch;
            }
        }
        return res;
    }
};