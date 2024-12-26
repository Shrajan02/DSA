#define mod 1000000007
class Solution {
private:
    long long power(long long x, long long n) {
        // Fast Binary Exponentiation 
        if (n == 0) return 1;

        long long half = power(x, n/2) % mod;
        half = (half * half) % mod;

        if (n % 2 == 1) { // odd
            half = (half * x) % mod;
        }
        return half;
    }

public:
    int countGoodNumbers(long long n) {
        long long even = n / 2 + n % 2;
        long long odd = n / 2;
        long long result = (power(5, even) * power(4, odd)) % mod;
        return result;
    }
};