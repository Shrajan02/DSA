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

// BFS approach
// TC: O(n)
// SC: O(n)
using ll = long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll maxWidth = 1;
        queue<pair<TreeNode*, ll>> q;  // {node, index}
        q.push({root, 1});

        while (!q.empty()) {
            ll first = q.front().second, last = q.back().second;
            maxWidth = max(last - first + 1, maxWidth);

            ll n = q.size();
            while (n--) {
                TreeNode* node = q.front().first;
                ll index = q.front().second - first;  // normalization (no overflow)
                q.pop();

                // if parent's index is n,
                // left child -> 2n, right child -> 2n + 1
                if (node->left) {
                    q.push({node->left, 2 * index});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }
        }

        return maxWidth;
    }
};