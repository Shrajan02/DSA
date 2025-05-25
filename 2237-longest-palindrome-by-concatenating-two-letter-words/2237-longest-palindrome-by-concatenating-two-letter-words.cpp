// Greedy Pairing + Hashing approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // create a frequency map
        unordered_map<string, int> hashMap;
        for (const auto& str: words) {
            hashMap[str]++;
        }

        int palindromeLen = 0;
        bool hasCenter = false;
        for (auto& [w, freq]: hashMap) {
            string str = w;
            reverse(str.begin(), str.end());

            // Case 1: Palindromic word (gg)
            if (w == str) {
                palindromeLen += (freq / 2) * 4;

                // 1 odd-palindrome word left
                if (freq % 2 == 1) {
                    hasCenter = true;
                }
            }

            // Case 2: Non palindromic word (ab/ba)
            else if (hashMap.count(str)) {
                palindromeLen += min(freq, hashMap[str]) * 4;
                hashMap[str] = 0; // mark visited
            }
        }  

        // If a palindromic word was left, use it as the center of the palindrome
        if (hasCenter) {
            palindromeLen += 2;
        }
        return palindromeLen;
    }
};