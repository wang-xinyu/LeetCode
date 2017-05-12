/**
 * Remove Duplicates from Sorted List
 * Very simple question
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
    ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode *temp = head; temp != NULL; temp = temp->next)
            while (temp->next && temp->val == temp->next->val) temp->next = temp->next->next;
        return head;
    }
};
