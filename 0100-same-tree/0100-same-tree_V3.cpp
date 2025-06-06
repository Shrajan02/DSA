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
// DFS approach using stacks
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1, s2;
        s1.push(p);
        s2.push(q);

        while (!s1.empty() && !s2.empty()) {
            TreeNode* node1 = s1.top();
            TreeNode* node2 = s2.top();
            s1.pop();
            s2.pop();

            if (!node1 && !node2) {
                continue;
            }
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }

            s1.push(node1->right);
            s1.push(node1->left);
            
            s2.push(node2->right);
            s2.push(node2->left);
        }
        return true;
    }
};
