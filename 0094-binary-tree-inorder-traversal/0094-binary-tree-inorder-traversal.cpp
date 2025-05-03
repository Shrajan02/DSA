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
// SC: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        dfs(root, inOrder);
        return inOrder;
    }

private:
    void dfs (TreeNode* node, vector<int>& inOrder) {
        if (!node) {
            return;
        }
        
        // left -> node -> right
        dfs(node->left, inOrder);
        inOrder.push_back(node->val);
        dfs(node->right, inOrder);
    }

};