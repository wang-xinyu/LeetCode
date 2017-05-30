/**
 * Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        ListNode *faster = head, *slower = head;
        while (faster != NULL && faster->next != NULL) {
            slower = slower->next;
            faster = faster->next->next;
            if (slower == faster) return true;
        }
        return false;
    }
};
