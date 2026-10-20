// Stack approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;

        for (char bracket : s) {
            if (bracket == '(') {
                st.push(bracket);
            }
            // when bracket is ')'
            else {
                if (st.empty() || st.top() == ')') {
                    st.push(bracket);
                }
                else if (st.top() == '(') {
                    st.pop();
                }
            }
        }

        return st.size();
    }
};