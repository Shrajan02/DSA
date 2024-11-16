class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string result = "";
        for (char c: s) {
            // First opening paranthesis
            if (c == '(' && balance == 0) {
                balance++;
            }
            // Last closing paranthesis
            else if (c == ')' && balance == 1) {
                balance = 0;
            }
            // Remaining parantheses
            else {
                result += c;
                if (c == '(')
                    balance++;
                else 
                    balance--;
            }
        }
        return result;
    }
};