class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (const char& ch: s) {
            if (!st.empty() && (st.top() == 'A' && ch == 'B')) {
                st.pop();
            }
            else if (!st.empty() && (st.top() == 'C' && ch == 'D')) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        return st.size();
    }
};