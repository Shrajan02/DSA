/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Recursive DFS + Hash Table approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int start = 0, end = n - 1;
        int index = 0; // maintains preorder position globally

        // find splits in O(1)
        unordered_map<int, int> inorderMap;
        int i = 0;
        for (const int& node : inorder) {
            inorderMap[node] = i++;
        }

        return solve(preorder, inorder, inorderMap, start, end, index);
    }

private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap, int start, int end, int& index) {
        // base case: when range is invalid to search
        if (start > end) {
            return NULL;
        }

        // search the root node in inorder to split left & right subtrees
        int rootVal = preorder[index];
        int split = inorderMap[rootVal];

        index++; // move to next element of preorder

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, inorderMap, start, split - 1, index);
        root->right = solve(preorder, inorder, inorderMap, split + 1, end, index);

        return root;
    }
};