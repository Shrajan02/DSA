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

// Morris traversal approach
// TC: O(n)
// SC: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // link the left child's rightmost node with the right child
                TreeNode* pred = curr->left;
                while (pred->right) {
                    pred = pred->right;
                }
                pred->right = curr->right;

                // flatten left subtree to right to maintain preorder
                curr->right = curr->left;  
                curr->left = NULL;
            }
            // move to the next node
            curr = curr->right;            
        }
    }
};