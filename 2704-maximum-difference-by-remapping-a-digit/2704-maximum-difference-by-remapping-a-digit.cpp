// Greedy approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);  
        int n = str.length();

        // replace first non-9 digit with '9' for max 
        char firstDigit = ' ';
        for (const char& ch: str) {
            if (ch != '9') {
                firstDigit = ch;
                break;
            }
        }
        string maxi = str;
        for (int i = 0; i < n; i++) {
            if (maxi[i] == firstDigit) {
                maxi[i] = '9';
            }
        }

        // replace first digit with '0' for min
        string mini = str;
        firstDigit = str[0];
        for (int i = 0; i < n; i++) {
            if (mini[i] == firstDigit) {
                mini[i] = '0';
            }
        }

        return (stoi(maxi) - stoi(mini));
    }
};