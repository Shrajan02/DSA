// Using circular array property (with Stack)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;  

        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];
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