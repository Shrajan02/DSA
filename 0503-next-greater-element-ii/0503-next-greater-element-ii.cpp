// Double Length Array approach
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2 * n);
        for (int i = 0; i < n; i++) {
            nums[i + n] = nums[i];
        }

        vector<int> res(n, -1);
        stack<int> st;  
        for (int i = 2*n-1; i >= 0; i--) {
            int curr = nums[i];
            while (!st.empty() && curr >= st.top()) {
                st.pop();
            }
            if (!st.empty() && i < n) {
                res[i] = st.top();
            }
            st.push(curr);
        }
        return res;
    }
};