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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0, end = preorder.size() - 1;
        int index = 0;  // maintains preorder position globally

        return solve(preorder, inorder, start, end, index);
    }

private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index) {
        // base case: when range is invalid to search
        if (start > end) {
            return NULL;   
        }

        // search the root node in inorder to split left & right subtrees
        int rootVal = preorder[index];

        int split = start;
        while (split <= end) {
            if (inorder[split] == rootVal) {
                break;
            }
            split++;
        }
        index++;  // move to next element of preorder

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, split - 1, index);
        root->right = solve(preorder, inorder, split + 1, end, index);

        return root;
    }
};