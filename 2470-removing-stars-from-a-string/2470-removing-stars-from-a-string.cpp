// TC: O(n)
// SC: O(n)
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (const char &ch: s) {
            if (ch == '*' && !st.empty()) {
                st.pop();
            }
            // scan non-star
            else {
                st.push(ch);
            }
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        std::reverse(res.begin(), res.end());

        return res;
    }
};