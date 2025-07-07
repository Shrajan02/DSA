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
        if (!root) return new TreeNode(val);

        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while (curr) {
            prev = curr;
            curr = (val < curr->val) ? curr->left : curr->right;
        }

        if (prev->val > val) {
            prev->left = new TreeNode(val);
        }
        else {
            prev->right = new TreeNode(val);
        }

        return root;
    }
};