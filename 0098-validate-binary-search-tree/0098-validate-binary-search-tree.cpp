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
using ll = long long;
class Solution {
private:
    void solve(TreeNode* node, ll low, ll high, bool& isValid) {
        if (!node || !isValid) return;  // early exit if already invalid

        // preorder traversal -> N, L, R
        isValid = (node->val > low) && (node->val < high);
        if (!isValid) return;  

        solve(node->left, low, node->val, isValid);
        solve(node->right, node->val, high, isValid);
    }

public:
    bool isValidBST(TreeNode* root) {
        ll low = LLONG_MIN, high = LLONG_MAX;
        bool isValid = true;
        solve(root, low, high, isValid);
        return isValid;
    }
};