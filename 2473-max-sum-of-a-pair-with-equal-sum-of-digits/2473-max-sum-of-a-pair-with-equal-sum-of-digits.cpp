// HashMap + Sorting approach
// TC: O(n.logn) 
// SC: O(n)
class Solution {
private:
    int calculateSumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> digiSum;  // {sum of digits -> vector of indices}

        // construct hash table
        for (int num: nums) {
            int sum = calculateSumOfDigits(num);
            digiSum[sum].push_back(num);
        }

        // linear scan to check for match
        int maxi = -1;
        for (auto& [key, values]: digiSum) {
            if (values.size() > 1) {
                sort(values.rbegin(), values.rend()); // descending sort
                maxi = max(maxi, values[0] + values[1]);
            }
        }
        return maxi;
    }
};