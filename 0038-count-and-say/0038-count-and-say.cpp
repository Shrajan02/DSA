// Recursive approach
// TC: O(2^n)
// SC: O(n)
class Solution {
public:
    string countAndSay(int n) {
        string result = generateString("1", n - 1);
        return result;
    }

private:
    string generateString(const string& base, int n) {
        if (n == 0) {
            return base;
        }

        string res = "";
        int currCount = 1;
        for (int i = 1; i < base.length(); i++) {
            if (base[i] == base[i - 1]) {
                currCount++;
            } 
            else {
                res += to_string(currCount) + base[i - 1];
                currCount = 1;
            }
        }
        res += to_string(currCount) + base.back(); // handle last group

        return generateString(res, n - 1);
    }
};
