class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();

        // Edge case: Single word sentences
        if (sentence.find(' ') == n) {
            return sentence[0] == sentence[n - 1];
        }

        // Process word boundary
        for (int i = 1; i < n - 1; i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        // Check if first character matches last character
        return (sentence[0] == sentence[n - 1]);
    }
};