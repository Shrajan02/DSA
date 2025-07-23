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

// Recursive Preorder approach
// TC: O(n)
// SC: O(h)
class Solution {
private:
    void dfs(TreeNode* node, int high, int& count) {
        if (!node) return;

        // preorder traversal -> N, L, R
        if (node->val >= high) {  // good node condition
            high = node->val;
            count++;
        }
        dfs(node->left, high, count);
        dfs(node->right, high, count);
    }

public:
    int goodNodes(TreeNode* root) {
        int high = INT_MIN, count = 0;
        dfs(root, high, count);
        return count;
    }
};