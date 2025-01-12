class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char &ch : s) {
            if (!st.empty() && 
                (ch == ')' && st.top() == '(' || 
                 ch == ']' && st.top() == '[' ||
                 ch == '}' && st.top() == '{')) {
                    st.pop();
            }
            else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};