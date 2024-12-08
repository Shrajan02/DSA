class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), longest = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxi = INT_MIN, mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }
                longest += (maxi - mini);
            }
        }
        return longest;
    }
};