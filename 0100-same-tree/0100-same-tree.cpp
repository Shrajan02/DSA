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
// Recursive (DFS) Preorder traversal approach
// TC: O(n)
// SC: O(h)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  // both trees NULL
        if (!p || !q) return false; // only one tree NULL
        if (p->val != q->val) return false;  // both node values different

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};