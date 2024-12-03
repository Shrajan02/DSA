// TC: O(n)
// SC: O(n)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int pointer = 0;
        for (int i = 0; i < s.length(); i++) { 
            // Add spaces before character
            if (pointer < spaces.size() && i == spaces[pointer]) {
                res += " ";
                pointer++;
            }
            res += s[i];
        }
        return res;
    }
};