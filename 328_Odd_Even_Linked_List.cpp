/**
 * Odd Even Linked List
 *
 * Trick: no trick
 *
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *p1 = dummy1, *p2 = dummy2, *p = head;
        while (p) {
            p1->next = p;
            p = p->next;
            p1 = p1->next;
            if (p) {
                p2->next = p;
                p = p->next;
                p2 = p2->next;
            }
        }
        p2->next = NULL;
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
