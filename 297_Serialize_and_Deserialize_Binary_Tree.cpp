/**
 * Serialize and Deserialize Binary Tree
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(NULL);
        TreeNode *cur = root;
        string encoded = ".";
        
        while (cur) {
            encoded += to_string(cur->val);
            if (cur->left && cur->right) {
                encoded += ":";
                s.push(cur->right);
                cur = cur->left;
            } else if (cur->left) {
                encoded += ".";
                cur = cur->left;
            } else if (cur->right) {
                encoded += "`";
                cur = cur->right;
            } else {
                encoded += "!";
                cur = s.top();
                s.pop();
            }
        }
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode*> s;
        TreeNode *root = new TreeNode(0);
        TreeNode *cur = root;
        int start = 0;
        while (start+1 != data.size()) {
            int end = start+1;
            while (data[end] == '-' || data[end] >= '0' && data[end] <= '9') end++;
            string str = data.substr(start+1, end-start-1);
            int num = atoi(str.c_str());
            if (data[start] == ':') {
                s.push(cur);
                cur->left = new TreeNode(num);
                cur = cur->left;
            } else if (data[start] == '.') {
                cur->left = new TreeNode(num);
                cur = cur->left;
            } else if (data[start] == '`') {
                cur->right = new TreeNode(num);
                cur = cur->right;
            } else if (data[start] == '!') {
                cur = s.top();
                s.pop();
                cur->right = new TreeNode(num);
                cur = cur->right;
            }
            start = end;
        }
        return root->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
