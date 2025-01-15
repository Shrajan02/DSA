// n -> num1, m -> num2
// TC: O(n + m) 
// SC: O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> res(n, -1); // result array
        stack<int> st; 
        unordered_map<int, int> hashMap;

        for (int num: nums2) {
            // pop elements from stack & update map
            while (!st.empty() && st.top() < num) {
                hashMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for (int i = 0; i < n; i++) {
            if (hashMap[nums1[i]]) {
                res[i] = hashMap[nums1[i]];
            }
        }
        return res;
    }
};