/**
 * Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        return buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, map);
    }
private:
    TreeNode* buildTree(vector<int>& postorder, int m1, int n1, vector<int>& inorder, int m2, int n2, unordered_map<int, int>& map) {
        if (m1 > n1) return NULL;
        int curindex = map[postorder[n1]];
        int new_right_m1 = n1 - (n2 - curindex);
        TreeNode *root = new TreeNode(postorder[n1]);
        root->left = buildTree(postorder, m1, new_right_m1-1, inorder, m2, curindex-1, map);
        root->right = buildTree(postorder, new_right_m1, n1-1, inorder, curindex+1, n2, map);
        return root;
    }
};
