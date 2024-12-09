class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), total = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0}; 
            int maxi = 0;      

            // Sliding window with'j'
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;  // Update the frequency of current character
                maxi = max(maxi, freq[s[j] - 'a']); 

                // Find the minimum frequency greater than 0
                int mini = INT_MAX;
                for (auto &k: freq) {
                    if (k > 0) {
                        mini = min(mini, k);
                    }
                }
                total += (maxi - mini);
            }
        }

        return total;
    }
};
