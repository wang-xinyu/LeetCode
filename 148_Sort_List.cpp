/**
 * Sort List
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
    ListNode* sortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head;
        int len = 0;
        while (p) {
            p = p->next;
            len++;
        }
        for (int step = 1; step < len; step <<= 1) {
            ListNode *p1 = dummy;
            while (p1->next) {
                ListNode *p2 = p1;
                int i = 0;
                for (; i < step && p2->next; i++) p2 = p2->next;
                ListNode *tail = p2;
                for (int j = 0; j < step && tail->next; j++) tail = tail->next;
                ListNode *nextHead = tail->next;
                tail->next = NULL;
                ListNode *temp = p2->next;
                p2->next = NULL;
                p1->next = mergeTwoSortedList(p1->next, temp, tail);
                tail->next = nextHead;
                p1 = tail;
            }
        }
        return dummy->next;
    }
private:
    ListNode* mergeTwoSortedList(ListNode* p1, ListNode* p2, ListNode* &tail) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1) p->next = p1;
        else if (p2) p->next = p2;
        tail = p;
        while (tail->next) tail = tail->next;
        return dummy->next;
    }
};
