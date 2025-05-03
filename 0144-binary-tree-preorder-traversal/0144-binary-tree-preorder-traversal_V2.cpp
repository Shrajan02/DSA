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
// Iterative DFS approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if (!root) return preOrder;  // edge case

        // root -> left -> right
        stack<TreeNode*> st;
        st.push(root); 

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            preOrder.push_back(node->val);     // root
            if (node->right) {
                st.push(node->right);          // right
            }
            if (node->left) {
                st.push(node->left);           // left
            }
        } 
        return preOrder;
    }
};
