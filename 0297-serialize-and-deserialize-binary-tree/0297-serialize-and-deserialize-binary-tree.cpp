/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Design
// TC: O(n)
// SC: O(n)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";

        string data = "[";
        queue<TreeNode*> q;
        q.push(root);
        // int height = findHeight(root);

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    data.append(to_string(node->val) + ',');
                    q.push(node->left);
                    q.push(node->right);
                } 
                else {
                    data.append("null,");
                }
            }
        }
        data[data.length() - 1] = ']';

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // "[1,2,3,null,null,4,5]"
        data = data.substr(1, data.length() - 2); // strip brackets
        if (data.empty()) return NULL;

        // convert data to array of strings
        vector<string> nodes;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        // ["1", "2", "3", "null", "null", "4", "5"]
        int n = nodes.size();
        if (nodes[0] == "null") return NULL;
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1; // next index in nodes

        while (!q.empty() && i < n) {
            TreeNode* node = q.front();
            q.pop();

            // left child
            if (nodes[i] != "null") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;

            // array can go out of bounds
            if (i >= n) {
                break;
            }

            // right child
            if (nodes[i] != "null") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));