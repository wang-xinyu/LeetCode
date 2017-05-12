/**
 * Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dump1 = new ListNode(0);
        ListNode *dump2 = new ListNode(0);
        ListNode *p1 = dump1, *p2 = dump2;
        while (head) {
            if (head->val < x) p1 = p1->next = head;
            else p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = dump2->next;
        return dump1->next;
    }
};
