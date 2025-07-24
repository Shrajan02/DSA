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

// Recursive Inorder approach
// TC: O(n)
// SC: O(h)
class Solution {
private:
    void calculateBSTDiff(TreeNode* node, int& min_diff, int& prev) {
        if (!node) return;

        // inorder traversal -> L, N, R
        calculateBSTDiff(node->left, min_diff, prev);
        
        if (prev != INT_MIN) { // skip the first node
            int curr_diff = std::abs(node->val - prev);
            min_diff = std::min(curr_diff, min_diff);
        }
        prev = node->val;

        calculateBSTDiff(node->right, min_diff, prev);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX, prev = INT_MIN;
        calculateBSTDiff(root, min_diff, prev);
        return min_diff;
    }
};