class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Edge case when s cannot be subsequence of t
        if (s.length() > t.length()) return false;

        int i = 0, j = 0;  // s -> i, t -> j
        while (j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return (i == s.length());
    }
};