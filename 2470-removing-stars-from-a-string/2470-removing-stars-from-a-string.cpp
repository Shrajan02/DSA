// TC: O(n)
// SC: O(n)
class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for (auto ch: s) {
            if (ch == '*') {
                res.pop_back();
            }
            // scan non-star
            else {
                res += ch;
            }
        }
        return res;
    }
};