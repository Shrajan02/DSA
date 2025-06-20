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

// Post-order Recursive approach
// TC: O(n)
// SC: O(h)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return {};

        // binary tree is recursive in nature
        invertTree(root->left);
        invertTree(root->right);

        // swap left & right child
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        return root;
    }
};