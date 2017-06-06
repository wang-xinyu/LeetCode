/**
 * Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA;
        int n1 = 0, n2 = 0;
        while (p) {
            n1++;
            p = p->next;
        }
        p = headB;
        while (p) {
            n2++;
            p = p->next;
        }
        ListNode *p1 = headA, *p2 = headB;
        while (n1 > n2) {
            p1 = p1->next;
            n1--;
        }
        while (n1 < n2) {
            p2 = p2->next;
            n2--;
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
