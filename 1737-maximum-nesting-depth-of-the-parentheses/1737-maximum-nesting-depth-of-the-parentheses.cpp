class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxi = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
                maxi = max(depth, maxi); 
            }
            else if (s[i] == ')') {
                depth--;
            }    
        }
        return maxi;
    }
};