/**
 * Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head;
        while (p->next) {
            ListNode *i = dummy;
            for (; i->next != p->next; i = i->next) {
                if (i->next->val <= p->next->val) continue;
                ListNode *temp1 = i->next;
                i->next = p->next;
                ListNode *temp2 = p->next->next;
                p->next->next = temp1;
                p->next = temp2;
                break;
            }
            if (i->next == p->next) p = p->next;
        }
        return dummy->next;
    }
};
