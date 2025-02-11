// Stack approach
// TC: O(n * m)
// SC: O(n + m)
class Solution {
private:
    bool checkMatch(stack<char>& st, string& part, int partLength) {
        stack<char> temp = st;
        for (int i = partLength - 1; i >= 0; i--) {
            // if current stack top doesn't match part character
            if (temp.top() != part[i]) {
                return false;
            }
            temp.pop();
        }
        return true;
    }

public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = part.length();

        for (const char& ch : s) {
            st.push(ch);
            // if stack size exceeds part length, check for match
            if (st.size() >= m && checkMatch(st, part, m)) {
                // if match, pop from original stack
                for (int j = 0; j < m; j++) {
                    st.pop();
                }
            }
        }

        // construct string from leftover stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};