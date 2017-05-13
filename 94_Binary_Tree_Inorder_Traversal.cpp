/**
 * Binary Tree Inorder Traversal
 * Recursion
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTrav(ans, root);
        return ans;
    }
private:
    void inorderTrav(vector<int> &ans, TreeNode* root) {
        if (root == NULL) return;
        if (root->left) inorderTrav(ans, root->left);
        ans.push_back(root->val);
        if (root->right) inorderTrav(ans, root->right);
    }
};

/**
 * Binary Tree Inorder Traversal
 * Use Stack
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            if (p) {  // Do not always see p->left, may die into infinite loop.
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                ans.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
