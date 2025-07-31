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

// Recursive approach
// TC: O(logn * logn)
// SC: O(logn)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        // calculate height of leftmost & leftmost paths
        int leftDepth = 0, rightDepth = 0;
        TreeNode* curr = root;
        while (curr) {
            leftDepth++;
            curr = curr->left;
        }
        curr = root;
        while (curr) {
            rightDepth++;
            curr = curr->right;
        }

        // perfect binary tree
        if (leftDepth == rightDepth) {
            return (1 << leftDepth) - 1;  // 2^h - 1
        }

        return (1 + countNodes(root->left) + countNodes(root->right));  // root + 2 children
    }
};