// Recursion approach
// TC: O(n^2)
// SC: O(n)
class Solution {
private:
    string generateBinaryString(string curr, int n, unordered_set<string>& hashSet) {
        // base case
        if (curr.size() == n) {
            // not a part of hashset
            if (hashSet.find(curr) == hashSet.end()) {
                return curr;
            }
            return "";   // failure of branch
        }

        // recursive step: 2 options -> 0 / 1
        string addZero = generateBinaryString(curr + "0", n, hashSet);
        if (addZero.length() > 0) {
            return addZero;
        }
        return generateBinaryString(curr + "1", n, hashSet);
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> hashSet;
        for (string str : nums) {
            hashSet.insert(str);
        }

        return generateBinaryString("", n, hashSet);
    }
};