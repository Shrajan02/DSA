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

// Dual Iterators approach (Space-optimized)
// TC: O(n)
// SC: O(h)
class Solution {
private:
    class BSTDualIterator { 
    private:
        stack<TreeNode*> st;
        bool reverse;

        // go all left or all right
        void pushAll(TreeNode* node) {
            while (node) {
                st.push(node);
                node = reverse ? node->right : node->left;
            }
        }
    
    public: 
        // constructor pre-fills stack
        BSTDualIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        int next() {
            TreeNode* node = st.top();
            st.pop();
            if (!reverse) {
                pushAll(node->right);  //  visited left, processed node and now right
            }
            else {
                pushAll(node->left);   
            }
            return node->val;
        }
    };

public:
    bool findTarget(TreeNode* root, int k) {
        BSTDualIterator low(root, false);   // in-order iterator (smallest first)
        BSTDualIterator high(root, true);   // reverse in-order iterator (largest first)

        // applying 2-pointers
        int i = low.next(), j = high.next();
        while (i < j) {
            int sum = i + j;
            if (sum < k) {
                i = low.next();
            }
            else if (sum > k) {
                j = high.next();
            }
            else {
                return true;
            }
        }

        return false;
    }
};