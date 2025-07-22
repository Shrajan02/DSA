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

// BFS using Deque (No reversal) approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode*> q;
        q.push(root);

        std::deque<vector<int>> dq;  // store levels in reverse order
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            dq.push_front(level);   // inserts front at O(1)
        }
        
        return (vector<vector<int>>(dq.begin(), dq.end()));
    }
};