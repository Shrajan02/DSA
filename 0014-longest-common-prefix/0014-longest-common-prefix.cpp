class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int mini = strs[0].length();
        for (int word = 1; word < strs.size(); word++) {
            mini = min((int)strs[word].length(), mini);
        }

        string prefix = "";
        int i = 0;
        while (i < mini) {
            char first = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (first != strs[j][i]) {
                    return prefix;
                }
            }
            prefix += first;
            i++;
        }
        return prefix;
    }
};