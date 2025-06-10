// Brute-force approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxDifference(string s) {
        // build frequency map
        vector<int> freq(26, 0);
        for (const char& ch: s) {
            freq[ch - 'a']++;
        }

        int maxOdd = 1, minEven = INT_MAX;
        for (int i = 0; i < 26; i++) {
            // even
            if (freq[i] % 2 == 0 && freq[i] != 0) {
                minEven = min(freq[i], minEven);
            }
            // odd
            else {
                maxOdd = max(freq[i], maxOdd);
            }
        }

        return (maxOdd - minEven);
    }
};