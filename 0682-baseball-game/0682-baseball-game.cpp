class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (const string& s: operations) {
            if (s == "C") {
                st.pop();
            }
            else if (s == "D") {
                st.push(2 * st.top());
            }
            else if (s == "+") {
                int top = st.top();
                st.pop();
                int newTop = top + st.top();
                st.push(top);
                st.push(newTop);
            }
            else {
                st.push(stoi(s));
            }
        }

        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};