class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length(), count = 1;
        string ans = "";
        ans += s[0];
        char letter = s[0];

        for (int i = 1; i < n; i++) {
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