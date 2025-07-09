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

// Recursive approach + preventing memory leaks
// TC: O(h)
// SC: O(h)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } 
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        // when node to be removed is found
        else {
            // Case 1: leaf node
            if (!root->left && !root->right) {
                delete (root);
                return NULL;
            }
            // Case 2: only 1 child
            if (!root->left || !root->right) {
                TreeNode* temp = root->left ? root->left : root->right;
                delete (root);
                return temp;
            }
            // Case 3: both children
            // replace node’s value with either
            // inorder predecessor: max in left subtree OR
            // inorder successor: min in right subtree
            TreeNode* temp = root->left;
            while (temp->right) {
                temp = temp->right;
            }
            root->val = temp->val;  // swap to make it a Case 1 or Case 2 node

            // go left to find swapped node
            root->left = deleteNode(root->left, temp->val);
        }

        return root;
    }
};
