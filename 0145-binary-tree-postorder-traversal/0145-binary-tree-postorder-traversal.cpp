/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Reversal of Preorder approach using 1 stack
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (!root) return postOrder;

        stack<TreeNode*> st;
        st.push(root);

        // stack root first & store it first
        // then stack left and next right 
        // store right first and next left
        // root -> right -> left (reverse storing)
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            postOrder.push_back(curr->val);

            if (curr->left) {
                st.push(curr->left);
            }
            if (curr->right) {
                st.push(curr->right);
            }
        }
        reverse(postOrder.begin(), postOrder.end());

        return postOrder;
    }
};