class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        // Edge case: Strings of length less than 3
        if (n < 3) {
            return n;
        }

        // Construct frequency array
        vector<int> freq(26, 0);
        for (char ch: s) {
            freq[ch - 'a']++;
        }

        int minLength = 0;
        // Make all frequencies at max 2
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue; // does not appear
            if (freq[i] % 2 == 1) {
                freq[i] = 1;
            }
            else {
                freq[i] = 2;
            }
            minLength += freq[i];
        }
        return minLength;
    }
};