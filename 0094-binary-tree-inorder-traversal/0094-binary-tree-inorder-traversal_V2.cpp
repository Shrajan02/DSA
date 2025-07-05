/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

// Morris Order Traversal approach
// WITHOUT preserving original tree structure
// TC: O(n)
// SC: O(1)
vector<int> getInOrderTraversal(TreeNode *root)
{
    if (!root) return {};

    vector<int> result;
    TreeNode* curr = root;

    while (curr) {
        if (curr->left) {
            TreeNode* leftTree = curr->left;
            // goto the rightmost node of left child
            while (leftTree->right) {
                leftTree = leftTree->right; 
            }
            leftTree->right = curr; // establish a link back to the current node 
            TreeNode* temp = curr; 
            curr = curr->left;
            temp->left = NULL;  // delete the previous left link else stuck in loop 
        }
        else {
            // {V, R}
            result.push_back(curr->data);
            curr = curr->right;
        }
    }
    return result;
}
