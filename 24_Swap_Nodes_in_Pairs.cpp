/**
 * Swap Nodes in Pairs
 * Time complexity: O(n)
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy, *a, *b;
        p->next = head;
        while ((a = head) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            p->next = b;
            p = p->next->next;
            head = head->next;
        }
        return dummy->next;
    }
};
