/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Iterative DFS approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);      // go as left as possible
                curr = curr->left;
            }

            // process the leftmost node
            curr = st.top();
            st.pop();
            inOrder.push_back(curr->val);

            // go right
            curr = curr->right;
        }
        return inOrder;
    }

};
