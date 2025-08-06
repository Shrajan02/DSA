class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();

        std::map<char, int> mp;
        int unique_count = 0;
        for (char c : tasks) {
            if (mp[c] == 0) {
                unique_count++;
            }
            mp[c]++;
        }

        int max_freq = 0;
        for (auto [_, count] : mp) {
            max_freq = std::max(max_freq, count);
        }

        int max_freq_count = 0;
        for (auto pair : mp) {
            if (pair.second == max_freq) {
                max_freq_count++;
            }
        }

        int cycles = max_freq - 1;
        int res = cycles * (n + 1) + max_freq_count;

        res = std::max(k, res);
        return res; 
    }
};