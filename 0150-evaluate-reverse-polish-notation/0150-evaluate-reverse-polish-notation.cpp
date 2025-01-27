class Solution {
private:
    int evaluateExp(int a, int b, char op) {
        switch (op) {
            case '+':
                return (a + b);
            case '-':
                return (a - b);
            case '*':
                return (a * b);
            case '/':
                return (a / b);
            }
        return 0;
    }

public:
    int evalRPN(vector<string>& tokens) {
        // Postfix to Infix
        stack<int> st;
        for (const string& curr : tokens) {
            // scan operators
            if (curr == "+" || curr == "-" || curr == "*" || curr == "/") {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                int temp = evaluateExp(op1, op2, curr[0]);
                st.push(temp);
            }
            // scan operands
            else {
                int num = stoi(curr);
                st.push(num);
            }
        }
        return st.top();
    }
};