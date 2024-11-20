class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t mini = SIZE_MAX;
        for (int word = 0; word < strs.size(); word++) {
            mini = min(strs[word].length(), mini);
        }
        string prefix = "";
        for (int i = 0; i < mini; i++) {
            char first = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (first != strs[j][i]) {
                    return prefix;
                }
            }
            prefix += first;
        }
        return prefix;
    }
};