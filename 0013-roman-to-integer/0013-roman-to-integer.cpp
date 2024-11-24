class Solution {
public:
    int romanToInt(string s) {
        // Create a dictionary to store Roman -> integer mappings
        unordered_map<char, int> romanMap = {
            {'I', 1},   
            {'V', 5},   
            {'X', 10},
            {'L', 50},  
            {'C', 100}, 
            {'D', 500},
            {'M', 1000}
        };

        int res = 0, n = s.length();
        for (int c = 0; c < n; c++) {
            int current = romanMap[s[c]];
            if (c < n - 1 && current < romanMap[s[c + 1]]) {
                res -= current;
            } else {
                res += current;
            }
        }
        return res;
    }
};