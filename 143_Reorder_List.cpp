/**
 * Reorder List
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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode *faster = head, *slower = head;
        // 1. find the middle point
        while (faster->next && faster->next->next) {
            slower = slower->next;
            faster = faster->next->next;
        }
        // 2. reverse the 2nd half
        ListNode *endOfFirstPart = slower, *lastReverse = NULL;
        while (endOfFirstPart->next) {
            ListNode *temp = endOfFirstPart->next;
            endOfFirstPart->next = endOfFirstPart->next->next;
            temp->next = lastReverse;
            lastReverse = temp;
        }
        // 3. merge
        ListNode *p1 = head, *p2 = lastReverse;
        while (p2) {
            ListNode *temp1 = p1->next;
            p1->next = p2;
            ListNode *temp2 = p2->next;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
    }
};
