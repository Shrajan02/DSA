// Monotonic Stack - NSE & PSEE approach
// TC: O(n)
// SC: O(n)
class Solution {
private:
    vector<int> calculateNSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> calculatePSEE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> psee(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> NSE = calculateNSE(arr, n);
        vector<int> PSEE = calculatePSEE(arr, n);
        long long result = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - PSEE[i];   // end at the current
            long long right = NSE[i] - i;  // start at the current
            result = (result + (arr[i] * left * right) % MOD) % MOD;  // contribution
        }
        return result;
    }
};