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
// Recursive Postorder DFS approach
// TC: O(n)
// SC: O(h)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }

private:
    int dfs(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }

        // postorder traversal
        int leftDepth = dfs(node->left, diameter);
        int rightDepth = dfs(node->right, diameter);
        diameter = max(leftDepth + rightDepth, diameter); // diameter of tree = height of left tree + height of right tree
        int depth = 1 + max(leftDepth, rightDepth);
        return depth;
    }
};