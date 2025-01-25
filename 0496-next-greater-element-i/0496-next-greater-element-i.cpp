// n -> num1, m -> num2
// TC: O(n + m) 
// SC: O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> result(n, -1); // result array
        unordered_map<int, int> nge; // nge hashmap
        stack<int> st;  // decreasing monotonic stack

        // Constructing nge hashmap for nums2
        for (int i = m - 1; i >= 0; i--) {
            int current = nums2[i];
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }
            if (!st.empty()) {
                nge[current] = st.top();
            }
            st.push(current);
        }

        // Build result nge array for nums1
        for (int j = 0; j < n; j++) {
            if (nge.find(nums1[j]) != nge.end()) {
                result[j] = nge[nums1[j]];
            }
        }
        return result;
    }
};