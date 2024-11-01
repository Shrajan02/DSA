class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) {
            return s;
        }

        string ans = "";
        ans += s[0];
        char letter = s[0];
        int count = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (letter != s[i]) {
                count = 1;
                letter = s[i];
                ans += s[i];
            }
            else {
                count++;
                if (count < 3) {
                    ans += s[i];
                } 
            }
        }
        return ans;
    }
};