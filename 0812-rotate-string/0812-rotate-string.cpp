class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        s += s; // abcdeabcde
        return (s.find(goal) != string::npos);
    }
};