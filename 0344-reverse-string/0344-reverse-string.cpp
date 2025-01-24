class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if (n == 1) return;  // edge case

        // 2-pointer approach
        int i = 0, j = n - 1;
        while (i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
};