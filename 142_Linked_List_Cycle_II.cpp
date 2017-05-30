/**
 * Linked List Cycle II
 * 
 * Slower and faster
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *faster = head, *slower = head;
        int a = 0;
        while (faster && faster->next) {
            slower = slower->next;
            faster = faster->next->next;
            a++;  //2a - a = nC, L1+L2 = a, L1 = a-L2 = nC-L2 = (n-1)C + (C-L2) 
            if (slower == faster) break;
        }
        if (faster == NULL || faster->next == NULL) return NULL;
        ListNode *cycleBegin = head;
        while (cycleBegin != slower) {
            cycleBegin = cycleBegin->next;
            slower = slower->next;
        }
        return cycleBegin;
    }
};
