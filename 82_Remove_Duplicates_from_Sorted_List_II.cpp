/**
 * Remove Duplicates from Sorted List II
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
        ListNode *dump = new ListNode(0);
        dump->next = head;
        int flag = 0;
        for (ListNode *temp = dump; temp->next != NULL;) {
            if (temp->next->next != NULL && temp->next->val == temp->next->next->val) flag = 1;
            else {
                temp = temp->next;
                continue;
            }
            while (temp->next->next != NULL && temp->next->val == temp->next->next->val) temp->next = temp->next->next;
            if (flag) {
                temp->next = temp->next->next;
                flag = 0;
            }
        }
        return dump->next;
    }
};
