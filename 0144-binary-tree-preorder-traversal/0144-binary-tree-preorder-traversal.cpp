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
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        dfs(root, preOrder);
        return preOrder;
    }

private:
    void dfs(TreeNode* node, vector<int>& preOrder) {
        if (!node) {
            return;
        }
        preOrder.push_back(node->val);  // visit root
        dfs(node->left, preOrder);      // traverse left
        dfs(node->right, preOrder);     // traverse right
    }
};