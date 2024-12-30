class Solution {
private:
    void generateLetters(vector<string>& result, const string& digits, string current, const unordered_map<char, string>& phoneNumber, int i) {
        if (i == digits.length()) {
            result.push_back(current);
            return;
        } 

        char digit = digits[i];
        for (char ch: phoneNumber.at(digit)) {
            current.push_back(ch);
            generateLetters(result, digits, current, phoneNumber, i + 1);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty())
            return result;

        unordered_map<char, string> phoneNumber = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        generateLetters(result, digits, "", phoneNumber, 0);
        return result;
    }
};