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
// DFS or Bottom-up DP approach
// TC: O(n)
// SC: O(h)
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = root->val;
        dfs(root, maxPathSum);
        return maxPathSum;
    }

private:
    int dfs(TreeNode* node, int& maxPathSum) {
        if (!node) return 0;  // edge case

        // postorder traversal 
        int leftSum = max(0, dfs(node->left, maxPathSum));
        int rightSum = max(0, dfs(node->right, maxPathSum));
        int currSum = node->val + leftSum + rightSum;

        maxPathSum = max(currSum, maxPathSum);

        // return max one-side path upward 
        int upwardSum = node->val + max(leftSum, rightSum);
        return upwardSum;
    }

};