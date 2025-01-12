class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        // odd length strings are invalid 
        if (n % 2 == 1) {
            return false; 
        }

        stack<int> open;  // indices of '('
        stack<int> wild;  // indices of wildcards '0'

        // First pass: ensure ')' can be matched
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1' && s[i] == '(') {
                open.push(i); 
            } 
            else if (locked[i] == '1' && s[i] == ')') {
                if (!open.empty()) {
                    open.pop(); // Match ')' with '('
                } 
                else if (!wild.empty()) {
                    wild.pop(); // Match ')' with wildcard
                } 
                else {
                    return false; // Unmatched ')'
                }
            } 
            else if (locked[i] == '0') {
                wild.push(i); // Store index of wildcard
            }
        }

        // Second pass: ensure '(' can be matched
        while (!open.empty()) {
            if (wild.empty() || wild.top() < open.top()) {
                return false; // Unmatched '('
            }
            open.pop();
            wild.pop(); // Use wildcards to match remaining '('
        }

        return true; 
    }
};
