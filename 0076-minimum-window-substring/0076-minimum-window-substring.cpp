// Sliding Window + Hashmap approach
// TC: O(n + m)
// SC: O(n + m)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if (n < m) return "";

        unordered_map<char, int> targetMap;
        for (char ch : t) {
            targetMap[ch]++;
        }
        int required = targetMap.size(); // unique characters in target

        unordered_map<char, int> windowMap;
        int minLen = INT_MAX, startIdx = -1;
        int left = 0, formed = 0;

        for (int right = 0; right < n; right++) {
            char ch = s[right];
            windowMap[ch]++;
            // if the current character's frequency in window matches required frequency
            if (targetMap.find(ch) != targetMap.end() &&
                windowMap[ch] == targetMap[ch]) {
                formed++;
            }
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;   // preserves start index of latest window
                }

                // shrink from left
                char leftChar = s[left];
                windowMap[leftChar]--;

                // if leftChar is in target
                if (targetMap.find(leftChar) != targetMap.end() && windowMap[leftChar] < targetMap[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
