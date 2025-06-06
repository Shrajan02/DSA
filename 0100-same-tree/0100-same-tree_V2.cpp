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
// BFS approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();

            // both NULL means identical 
            if (!node1 && !node2) {
                continue;
            }
            // any 1 NULL or different values mean non-identical
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }

            // add left & right subtrees
            q1.push(node1->left);
            q1.push(node1->right);
            
            q2.push(node2->left);
            q2.push(node2->right);
        }  

        return true;
    }
};
