/**
 * Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        dummy1->next = head;
        while (dummy1->next) {
            ListNode *p = dummy2->next;
            dummy2->next = dummy1->next;
            dummy1->next = dummy1->next->next;
            dummy2->next->next = p;
        }
        return dummy2->next;
    }
};
