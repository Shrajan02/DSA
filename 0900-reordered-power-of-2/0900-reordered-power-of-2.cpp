class Solution {
private:
    vector<int> countDigits(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        return freq;
    }

    bool equalFreq(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
            
        return true;
    }

public:
    bool reorderedPowerOf2(int N) {
        vector<int> target = countDigits(N); // count frequency of digits

        // check all powers of 2 up to 2^30 (fits in 32-bit signed int i.e till limit = 10^9)
        for (int i = 0; i <= 30; i++) {
            int power_two = (int)std::pow(2, i); // 2^i

             // compare frequency arrays for equality
            if (equalFreq(target, countDigits(power_two))) {
                return true;
            } 
        }

        return false;
    }
};