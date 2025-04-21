// Iterative approach
// TC: O(2^n)
// SC: O(2^n)
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            int currCount = 1;
            string temp = "";
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == res[j - 1]) {
                    currCount++;
                }
                else {
                    temp += to_string(currCount) + res[j - 1];
                    currCount = 1;
                }
            }
            temp += to_string(currCount) + res.back();
            res = temp;
        }
        return res;
    }
};
