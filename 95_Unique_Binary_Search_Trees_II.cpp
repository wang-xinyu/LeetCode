/**
 * Unique Binary Search Trees II
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
class solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return (n == 0) ? vector<TreeNode*>() : generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int m, int n) {
        vector<TreeNode*> ret;
        if (m > n) {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = m; i <= n; i++) {
            vector<TreeNode*> l = generateTrees(m, i-1);
            vector<TreeNode*> r = generateTrees(i+1, n);
            for (TreeNode* nodel : l) {
                for (TreeNode* noder : r) {
                    TreeNode *root = new TreeNode(i);
                    root->left = nodel;
                    root->right = noder;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
