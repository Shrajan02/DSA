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
// Recursive DFS approach
// TC: O(n)
// SC: O(h) 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isTreeBalanced = true;
        height(root, isTreeBalanced);
        return isTreeBalanced;
    }

private:
    int height(TreeNode* node, bool& isTreeBalanced) {
        if (!node || !isTreeBalanced) {
            return 0;
        }

        int leftDepth = height(node->left, isTreeBalanced);
        int rightDepth = height(node->right, isTreeBalanced);

        if (abs(leftDepth - rightDepth) > 1) {
            isTreeBalanced = false;
        }

        return 1 + max(leftDepth, rightDepth);
    }
};
