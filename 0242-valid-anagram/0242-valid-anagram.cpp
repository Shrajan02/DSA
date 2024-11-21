// TC: O(n) ; n -> length of string 't'
// SC: O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> hashMap;
        int i = 0, n = s.length();
        while (i < n) {
            hashMap[s[i]]++;
            hashMap[t[i]]--;
            i++;
        }

        // Check if all counts are zero
        for (auto count : hashMap) {
            if (count.second != 0) {
                return false;
            }
        }
        return true;
    }
};
