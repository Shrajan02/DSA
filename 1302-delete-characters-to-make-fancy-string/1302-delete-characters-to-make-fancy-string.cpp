class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) {
            return s;
        }
        string ans = "";
        ans += s[0];
        int count = 1;

        // back() -> returns a reference to the last element pf string
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != ans.back()) {
                count = 1;
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