/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Optimized Iterative BST approach
// TC: O(h)
// SC: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        // use BST property 
        while (curr) {
            if (curr->val > p->val && curr->val > q->val) {
                curr = curr->left;
            }
            else if (curr->val < p->val && curr->val < q->val) {
                curr = curr->right;
            }
            // LCA is found
            else {
                return curr;
            }
        }
        return NULL;
    }
};