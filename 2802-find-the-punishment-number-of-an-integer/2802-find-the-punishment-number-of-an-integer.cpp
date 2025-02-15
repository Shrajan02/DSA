class Solution {
private:
    bool canPartition(string &s, int index, int target) {
        if (index == s.length()) {
            return (target == 0);
        }

        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');   // convert substring to number incrementally
            if (num > target) break;  // stop early if number exceeds target

            if (canPartition(s, i + 1, target - num)) {
                return true;
            }
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int punishment = 0;
        for (int i = 1; i <= n; i++) {
            int squared = i * i;
            string str = to_string(squared);
            if (canPartition(str, 0, i)) {
                punishment += squared;
            }
        }
        return punishment;
    }
};
