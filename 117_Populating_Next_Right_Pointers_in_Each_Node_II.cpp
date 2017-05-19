/**
 * Populating Next Right Pointers in Each Node II
 *
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;
        while (p) {
            TreeLinkNode *nextHead = new TreeLinkNode(0);
            TreeLinkNode *nextP = nextHead;
            while (p) {
                if (p->left) {
                    nextP->next = p->left;
                    nextP = nextP->next;
                }
                if (p->right) {
                    nextP->next = p->right;
                    nextP = nextP->next;
                }
                p = p->next;
            }
            p = nextHead->next;
        }
    }
};
