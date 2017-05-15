/**
 * Validate Binary Search Tree 
 * Inorder traversal
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
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                if (!values.empty() && p->val <= values.back()) return false;
                values.push_back(p->val);
                p = p->right;
            }
        }
        return true;
    }
};
