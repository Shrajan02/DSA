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

// Insert into BST approach
// TC: O(n^2)
// SC: O(h)
class Solution {
private:
    void insertIntoBST(TreeNode* node, int key) {
        if (!node) node = new TreeNode(key);

        else if (node->val > key) {
            if (!node->left) {
                node->left = new TreeNode(key);
            }
            else {
                insertIntoBST(node->left, key);
            }
        }
        else {
            if (!node->right) {
                node->right = new TreeNode(key);
            }
            else {
                insertIntoBST(node->right, key);
            }
        }
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < n; i++) {
            insertIntoBST(root, preorder[i]);
        }

        return root;
    }
};