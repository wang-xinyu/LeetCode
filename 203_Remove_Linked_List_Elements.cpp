/**
 * Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        for (ListNode *p = dummy; p->next;) {
            if (p->next->val == val) p->next = p->next->next;
            else p = p->next;
        }
        return dummy->next;
    }
};
