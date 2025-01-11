class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        // Edge case: Palindromes more than length of string is impossible
        if (k > n) {
            return false;
        }
        
        // Build frequency table
        int frequency[26] = {0};
        for (char ch: s) {
            frequency[ch - 'a']++;
        }

        // Count characters with odd frequencies
        int odd = 0;
        for (int i: frequency) {
            if (i % 2 == 1) {
                odd++;
            }
        }
        return (odd <= k);
    }
};