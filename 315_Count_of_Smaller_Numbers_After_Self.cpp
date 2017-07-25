/**
 * Count of Smaller Numbers After Self 
 * 
 * Trick: build a BST, insert node one by one.
 */
class Solution {
    class Node {
    public:
        int sum, val, dup = 1;
        Node *left, *right;
        Node(int i, int j) : val(i), sum(j), left(NULL), right(NULL) {}
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        int n = nums.size();
        vector<int> counts(n);
        Node *root = NULL;
        for (int i = n-1; i >= 0; i--) {
            root = insertNode(nums[i], root, counts, i, 0);
        }
        return counts;
    }
private:
    Node* insertNode(int num, Node *root, vector<int> &counts, int i, int preSum) {
        if (root == NULL) {
            root = new Node(num, 0);
            counts[i] = preSum;
        } else if (root->val == num) {
            root->dup++;
            counts[i] = preSum + root->sum;
        } else if (root->val > num) {
            root->sum++;
            root->left = insertNode(num, root->left, counts, i, preSum);
        } else {
            root->right = insertNode(num, root->right, counts, i, preSum + root->dup + root->sum);
        }
        return root;
    }
};
