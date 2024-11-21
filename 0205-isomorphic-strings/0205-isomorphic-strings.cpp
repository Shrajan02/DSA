class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMapS, hashMapT; // 2 hash tables for bidirectional one-one mapping
        int n = s.length(), i = 0;
        
        while (i < n) {
            char charS = s[i], charT = t[i];
            // Check if mappings exist & are consistent
            if ((hashMapS.find(charS) != hashMapS.end() &&
                 hashMapS[charS] != charT) ||
                (hashMapT.find(charT) != hashMapT.end() &&
                 hashMapT[charT] != charS)) {
                return false;
            }
            // Add the mappings
            hashMapS[charS] = charT;
            hashMapT[charT] = charS;
            i++;
        }
        return true;
    }
};