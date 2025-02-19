// Monotonic stack approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (const char &ch: num) {
            // num[i] > num[i + 1] -> delete
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // remove remaining k digits from stack
        while (!st.empty() && k--) {
            st.pop();
        }

        // handling empty strings
        if (st.empty()) {
            return "0";
        }

        // construct resultant string from stack
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        std::reverse(res.begin(), res.end());

        // remove leading zeros by skipping any initial '0's. 
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }
        res = res.substr(i);
        
        return (res.empty() ? "0" : res);
    }
};