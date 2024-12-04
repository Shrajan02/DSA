class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        // Early exit
        if (m < n) return false;

        int i = 0, j = 0;  // i -> str1 , j -> str2
        while (i < m && j < n) {
            int cycle = (str2[j] - str1[i] + 26) % 26;  
            if (cycle == 1 || str1[i] == str2[j]) {
                j++;
            }
            i++;
        }
        return (j == n);
    }
};