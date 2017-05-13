/**
 * Reverse Linked List II
 * one-pass
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode *dump = new ListNode(0);
        dump->next = head;
        ListNode *p = dump, *e = NULL;
        int t = m;
        while (t-- > 1) p = p->next;
        ListNode *reverseEnd = p->next, *lastReverse = NULL;
        for (int i = m; i < n; i++) {
            ListNode *temp = p->next;
            p->next = p->next->next;
            temp->next = lastReverse;
            lastReverse = temp;
        }
        reverseEnd->next = p->next->next;
        p->next->next = lastReverse;
        return dump->next;
    }
};
