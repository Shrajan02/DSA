// TC: O(n)
// SC: O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int current = 0, left = 0, right = 0;
        while (current < n) {
            // skip the leading whitespaces
            while (current < n && s[current] == ' ') 
                current++;
            // end if no more words ahead
            if (current == n) 
                break;
            // copy the characters of a word to the correct position
            while (current < n && s[current] != ' ') {
                s[right++] = s[current++];
            }
            // reverse the current word
            reverse(s.begin() + left, s.begin() + right);
            // add space between the words
            s[right++] = ' ';
            left = right;
            current++;
        }
        // remove any extra space at the end
        s.resize(right - 1);
        return s;
    }
};