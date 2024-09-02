class Solution {
public:
    bool isPalindrome(int x) {
        int dig, copy = x;
        long rev = 0;
        if (copy < 0) 
            return false;
        while (copy != 0) {
            dig = copy % 10;
            rev = rev*10 + dig;
            copy /= 10;
        }
        return (rev == x);
    }
};