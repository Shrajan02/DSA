// TC: O(n)
// SC: O(n)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        // construct prefix sum array
        vector<long long> prefixSum(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            prefixSum[i] = sum;
        }
        
        // count number of odd & even elements in prefix-sum
        int odd = 0, even = 0;
        for (int val: prefixSum) {
            if (val % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }

        // main observation: ODD * (EVEN + 1)
        long long ans = (1LL * odd * (even + 1)) % MOD;
        return ans;
    }
};