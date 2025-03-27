// Sliding Window + Hash Set approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        unordered_set<char> freq;   
        int start = 0;    
        for (int end = 0; end < n; end++) {
            // duplicate characters  
            while (freq.find(s[end]) != freq.end()) {
                freq.erase(s[start]);
                start++;
            }
            freq.insert(s[end]); 
            maxLen = max(end - start + 1, maxLen);
        }
        return maxLen;
    }
};