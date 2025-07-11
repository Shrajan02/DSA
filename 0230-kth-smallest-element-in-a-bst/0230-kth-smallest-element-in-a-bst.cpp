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

// Recursive Inorder traversal approach
// TC: O(n)
// SC: O(h)
class Solution {
private:
    int res;
    int minIndex = 0;

    void solve(TreeNode* node, const int& k) {
        if (!node) return;

        // inorder traversal -> L, N, R
        solve(node->left, k);
        
        minIndex++;
        if (minIndex == k) {
            res = node->val;
            return;
        }
        
        solve(node->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return res;
    }
};