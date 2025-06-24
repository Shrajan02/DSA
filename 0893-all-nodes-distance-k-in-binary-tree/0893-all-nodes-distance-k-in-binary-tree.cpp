/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS + Parent Mapping approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // construct parent pointers
        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParent(root, parent_map);

        // bfs from target while keeping track of visited nodes
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int distance = 0;

        while (!q.empty()) {
            int n = q.size();
            if (distance == k) {
                break;
            }

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // left
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                // right
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                // parent
                if (parent_map.count(node) &&
                    !visited.count(parent_map[node])) {
                    q.push(parent_map[node]);
                    visited.insert(parent_map[node]);
                }
            }
            distance++;
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }

private:
    void markParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        if (!node) return;

        // preorder dfs
        if (node->left) {
            parent_map[node->left] = node;
            markParent(node->left, parent_map);
        }
        if (node->right) {
            parent_map[node->right] = node;
            markParent(node->right, parent_map);
        }
    }
};