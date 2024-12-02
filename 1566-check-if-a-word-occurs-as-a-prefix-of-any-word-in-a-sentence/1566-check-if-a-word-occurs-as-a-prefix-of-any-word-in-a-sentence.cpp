class Solution {
public:
    int isPrefixOfWord(string sentence, string search) {
        int n = search.length();
        if (sentence.substr(0, n) == search)
            return 1;

        int count = 1; // 1-based indexing
        for (int i = 0; i < sentence.length(); i++) {
            // Check for leading spaces
            if (sentence[i] == ' ') {
                count++;
                string window = sentence.substr(i + 1, n);
                if (window == search) {
                    return count;
                }
            }
        }
        return -1;
    }
};