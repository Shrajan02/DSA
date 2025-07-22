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

// BFS using Queue + Stack approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        std::queue<TreeNode*> q;
        q.push(root);

        // use queue (FIFO) to traverse nodes in a specific level
        // to reverse the order later (LIFO), use stack
        stack<vector<int>> st;
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
            st.push(level);
        }

        vector<vector<int>> bfs;
        while (!st.empty()) {
            bfs.push_back(st.top());
            st.pop();
        }
    
        return bfs;
    }
};