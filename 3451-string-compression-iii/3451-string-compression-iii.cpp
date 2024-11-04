class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1, n = word.size();
        for (int i = 1; i < n; i++) {
            // does not match the previous OR exceeds count
            if (word[i] != word[i - 1] || count >= 9) {
                comp += to_string(count);
                comp += word[i - 1];
                count = 1;
                
            }
            // matches the previous
            else {
                count++;
            }
        }
        // Last character still left
        comp += to_string(count);
        comp += word[n - 1];

        return comp;
    }
};