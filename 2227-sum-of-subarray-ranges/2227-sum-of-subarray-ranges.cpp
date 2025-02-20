// Monotonic Stack Approach (using concepts of NGE, NSE, PGEE, PSEE)
// TC: O(n)
// SC: O(n)
class Solution {
private:
    vector<int> calculateNSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            nse[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return nse;
    }

    vector<int> calculateNGE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }
            nge[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
        return nge;
    }

    vector<int> calculatePSEE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> psee(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            psee[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return psee;
    }

    vector<int> calculatePGEE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> pgee(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                st.pop();
            }
            pgee[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return pgee;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        // Range = Max - Min (valid for all subarrays)
        int n = nums.size();
        // max contribution
        vector<int> pgee = calculatePGEE(nums, n);
        vector<int> nge = calculateNGE(nums, n);
        long long maxTotal = 0;
        for (int i = 0; i < n; i++) {
            int maxLeft = i - pgee[i];
            int maxRight = nge[i] - i;
            maxTotal += 1LL * nums[i] * maxLeft * maxRight;
        }

        // min contribution
        vector<int> psee = calculatePSEE(nums, n);
        vector<int> nse = calculateNSE(nums, n);
        long long minTotal = 0;
        for (int j = 0; j < n; j++) {
            int minLeft = j - psee[j];
            int minRight = nse[j] - j;
            minTotal += 1LL * nums[j] * minLeft * minRight;
        }

        long long range = maxTotal - minTotal;
        return range;
    }
};