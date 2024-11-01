class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length(), count = 0;
        string ans = "";
        char letter = s[0];
        for (int i = 0; i < n; i++) {
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