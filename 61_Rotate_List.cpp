/**
 * Rotate List
 * Time complexity: O(n)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode *oldtail = head, *newtail = head;
        int n = 1;
        while (oldtail->next != NULL) {
            n++;
            oldtail = oldtail->next;
        }
        k %= n;
        if (k == 0) return head;
        for (int i = 1; i < n-k; i++) newtail = newtail->next;
        ListNode *newhead = newtail->next;
        oldtail->next = head;
        newtail->next = NULL;
        return newhead;
    }
};
