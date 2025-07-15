/**
 * Definition for a binary tree root.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursive Bound Checking approach
// TC: O(n)
// SC: O(h)
class Solution {
private:
    TreeNode* constructBST(vector<int>& preorder, int& index, int low, int high) {
        // base case
        if (index >= preorder.size()) {
            return NULL;
        }
        // if value out of bounds, stop
        if (preorder[index] < low || preorder[index] > high) {
            return NULL;
        }

        // preorder traversal
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left = constructBST(preorder, index, low, root->val);
        root->right = constructBST(preorder, index, root->val, high);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN, maxi = INT_MAX;
        int index = 0;
        TreeNode* root = constructBST(preorder, index, mini, maxi);
        return root;
    }
};