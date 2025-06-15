// Greedy Math approach (without strings)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int maxDiff(int num) {
        // extract digits from number
        vector<int> digits;
        while (num > 0) {
            int digit = num % 10;
            digits.push_back(digit);
            num /= 10;
        }
        int n = digits.size();
        reverse(digits.begin(), digits.end());

        // [8, 2, 9]
        // find first non-9 digit for max
        vector<int> a;
        int maxi = INT_MIN;
        for (int& val : digits) {
            if (val != 9) {
                maxi = val;
                break;
            }
        }
        // replace maxi with 9
        for (int& val : digits) {
            if (val == maxi) {
                a.push_back(9);
            } 
            else {
                a.push_back(val);
            }
        }

        // for mini,
        // if first digit is 1, find first non-0 non-1 digit
        // if first digit is not 1, replace it with 1
        vector<int> b;
        int mini = INT_MAX;

        if (digits[0] == 1) {
            for (int i = 1; i < n; i++) {
                if (digits[i] != 0 && digits[i] != 1) {
                    mini = digits[i];
                    break;
                }
            }
            for (int& val : digits) {
                if (val == mini) {
                    b.push_back(0);
                } 
                else {
                    b.push_back(val);
                }
            }
        } 
        else {
            mini = digits[0];
            for (int& val : digits) {
                if (val == mini) {
                    b.push_back(1);
                } 
                else {
                    b.push_back(val);
                }
            }
        }

        // a = [9, 2, 9]
        // b = [1, 2, 9]
        // digits = [8, 0, 0]
        int a_num = 0, b_num = 0;
        for (int i = 0; i < n; i++) {
            a_num = a_num * 10 + a[i];
            b_num = b_num * 10 + b[i];
        }

        return (a_num - b_num);
    }
};