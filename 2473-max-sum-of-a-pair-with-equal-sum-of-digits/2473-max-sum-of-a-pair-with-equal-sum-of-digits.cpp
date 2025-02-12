// HashMap (max value) approach
// TC: O(n) 
// SC: O(n)
class Solution {
private:
    int calculateSumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> digiSum;  // {sum of digits -> vector of indices}
        int maxi = -1;

        // 1-pass check
        for (int num: nums) {
            int key = calculateSumOfDigits(num);
            if (digiSum.find(key) != digiSum.end()) {
                maxi = max(maxi, digiSum[key] + num);
                digiSum[key] = max(digiSum[key], num);  // if greater number with same sum 
            }
            else {
                digiSum[key] = num;
            }
        }
        return maxi;
    }
};