class Solution {
public:
    int romanToInt(string s) {
        // Create a dictionary to store Roman -> integer mappings
        unordered_map<char, int> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;

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