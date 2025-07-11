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

// Inorder traversal + 2-pointers approach
// TC: O(n)
// SC: O(n) 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        dfs(root, nodes);  // construct sorted array

        // using 2-pointers
        // [2,3,4,5,6,7] ; k = 10
        int i = 0, j = nodes.size() - 1;
        while (i < j) {
            int sum = nodes[i] + nodes[j];
            if (sum < k) {
                i++;
            }
            else if (sum > k) {
                j--;
            }
            else {
                return true;
            }
        }

        return false;
    }

private:
    void dfs(TreeNode* node, vector<int>& nodes) {
        if (!node) return;

        // inorder traversal
        dfs(node->left, nodes);
        nodes.push_back(node->val);
        dfs(node->right, nodes);
    }
};