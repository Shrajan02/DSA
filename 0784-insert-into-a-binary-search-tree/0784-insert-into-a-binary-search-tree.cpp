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

// Iterative approach
// TC: O(h)
// SC: O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) return node;

        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while (curr) {
            prev = curr;
            curr = (val < curr->val) ? curr->left : curr->right;
        }
        prev->val > val ? (prev->left = node) : (prev->right = node);

        return root;
    }
};