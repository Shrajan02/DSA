class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size(), count = 0;
        for (auto s : words) {
            if (s.size() < len) {
                continue;
            }  
            count += (s.substr(0, len) == pref);
        }
        return count;
    }
};