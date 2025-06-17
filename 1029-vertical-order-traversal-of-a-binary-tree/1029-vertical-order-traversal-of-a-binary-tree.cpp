// DFS + Hash Table approach
// TC: O(nlogn)
// SC: O(n)
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
    
        // assign level & vertical coordinates
        vector<vector<int>> res;
        map<pair<int, int>, multiset<int>> mp;  // {[row, col], sorted list of nodes}
        dfs (root, 0, 0, mp);

        // group nodes by column
        // if same column, check row
        // if same row, check values
        map<int, vector<int>> sortedMap;  // {column, sortedList}
        for (auto &[coordinates, temp]: mp) {
            int row = coordinates.first;
            int col = coordinates.second;

            for (int node: temp) {
                sortedMap[col].push_back(node);  
            }
        }

        for (auto &[col, sortedList]: sortedMap) {
            res.push_back(sortedList);
        }
        
        return res;
    }

private:
    void dfs(TreeNode* node, int x, int y, map<pair<int, int>, multiset<int>> &mp) {
        if (!node) {
            return;
        }

        mp[{x, y}].insert(node->val);
        dfs(node->left, x + 1, y - 1, mp);
        dfs(node->right, x + 1, y + 1, mp);
    }
};