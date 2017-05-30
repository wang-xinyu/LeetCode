/**
 * Binary Tree Postorder Traversal 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> v;
        TreeNode *p = root;
        v.push(NULL);
        while (p) {
            ans.insert(ans.begin(), p->val);
            if (p->right) {
                if (p->left) v.push(p->left);
                p = p->right;
            } else if (p->left) {
                p = p->left;
            } else {
                p = v.top();
                v.pop();
            }
        }
        return ans;
    }
};
