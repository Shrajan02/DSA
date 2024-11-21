// TC: O(n) ; n -> length of string 't'
// SC: O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> hashMapS, hashMapT;
        for (int i = 0; i < s.length(); i++) {
            hashMapS[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            hashMapT[t[i]]++;
        }

        int i = 0, n = t.length();
        while (i < n) {
            if (hashMapS[t[i]] != hashMapT[t[i]]) {
                return false;
            }
            i++;
        }
        return true;
    }
};