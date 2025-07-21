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
// Brute force using Inorder Traversal approach
// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        // Inorder traversal of a BST always yields a sorted array 
        std::vector<int> inorder;
        sortedDFS(root, inorder);

        int index = 0;
        constructInorderBST(root, inorder, index);
    }

private:
    void sortedDFS(TreeNode* node, vector<int>& inorder) {
        if (!node) return;

        // inorder traversal: L -> N -> R
        sortedDFS(node->left, inorder);
        inorder.push_back(node->val);
        sortedDFS(node->right, inorder);

        ranges::sort(inorder);
    }

    void constructInorderBST(TreeNode* node, const vector<int>& result, int& index) {
        if (!node) return;

        constructInorderBST(node->left, result, index);
        node->val = result[index++];
        constructInorderBST(node->right, result, index);
    }
};