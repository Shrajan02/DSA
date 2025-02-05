class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        int n = s1.length();
        int freq1[26] = {0}, freq2[26] = {0}; // {char->s1, index}
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            char ch1 = s1[i], ch2 = s2[i];
            if (ch1 != ch2) {
                swaps++;
            }
            if (swaps > 2) {
                return false;
            }
            freq1[ch1 - 'a']++;
            freq2[ch2 - 'a']++;
        }

        // check frequencies when swaps <= 2
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
};