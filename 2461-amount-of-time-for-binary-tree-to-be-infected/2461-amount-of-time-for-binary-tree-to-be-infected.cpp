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

// BFS + DFS (Parent Mapping) + Hash Table approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // construct parent pointers
        unordered_map<TreeNode*, TreeNode*> parentMap;
        markParent(root, parentMap);

        // find target using dfs
        TreeNode* target = findTargetNode(root, start);

        // level-order traversal from target
        int time = 0;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while (!q.empty()) {
            int n = q.size();
            bool levelInfected = false;

            while (n--) {
                TreeNode* infectedNode = q.front();
                q.pop();
                // left
                if (infectedNode->left && !visited.count(infectedNode->left)) {
                    q.push(infectedNode->left);
                    visited.insert(infectedNode->left);
                    levelInfected = true;
                }
                // right
                if (infectedNode->right && !visited.count(infectedNode->right)) {
                    q.push(infectedNode->right);
                    visited.insert(infectedNode->right);
                    levelInfected = true;
                }
                // parent
                if (parentMap.count(infectedNode) && !visited.count(parentMap[infectedNode])) {
                    q.push(parentMap[infectedNode]);
                    visited.insert(parentMap[infectedNode]);
                    levelInfected = true;
                }
            }
            // increment per level
            if (levelInfected) {
                time++;
            }
        }

        return time;
    }

private:
    void markParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!node) return;

        if (node->left) {
            parentMap[node->left] = node;
            markParent(node->left, parentMap);
        }
        if (node->right) {
            parentMap[node->right] = node;
            markParent(node->right, parentMap);
        }
    }

    TreeNode* findTargetNode(TreeNode* node, int targetVal) {
        if (!node) return {};

        // preorder dfs
        if (node->val == targetVal) {
            return node;
        }
        TreeNode* leftSearch = findTargetNode(node->left, targetVal);
        if (leftSearch) {
            return leftSearch;
        }
        TreeNode* rightSearch = findTargetNode(node->right, targetVal);
        return rightSearch;
    }
};