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
// Iterative approach using 2 stacks
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (!root) return postOrder;

        // st1: normal traversal, st2: reverse storing
        stack<TreeNode*> st1, st2;
        st1.push(root);

        // stack root first & store it first
        // then stack left and next right 
        // store right first and next left
        while (!st1.empty()) {
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left) {
                st1.push(curr->left);
            }
            if (curr->right) {
                st1.push(curr->right);
            }
        }

        // root -> right -> left (reverse storing)
        while (!st2.empty()) {
            TreeNode* node = st2.top();
            st2.pop();
            postOrder.push_back(node->val);
        }

        return postOrder;
    }
};