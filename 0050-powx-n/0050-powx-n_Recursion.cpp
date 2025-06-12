// Fast Exponentiation approach
// TC: O(log(n))
// SC: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        
        // handling negative powers
        if (n < 0) {
            x = 1.0 / x;
            if (n == INT_MIN) {
                return x * myPow(x, INT_MAX);
            }
            n = -n;
        }

        // recursion 
        double half = myPow(x, n/2);
        if (n % 2 == 0) {
            return (half * half);
        }
        else { // if n -> odd
            return (half * half * x);
        }
    }
};
