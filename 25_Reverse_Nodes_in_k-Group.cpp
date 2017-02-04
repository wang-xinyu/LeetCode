/**
 * Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *pre = new_head;
        while (pre->next) {
            int count = 0;
            ListNode *currHead = pre->next;
            ListNode *currTail = pre->next;
            while (currTail && count != k) {
                currTail = currTail->next;
                count++;
            }
            if (count == k) {
                while (count-- > 0) {
                    ListNode *tmp = pre->next->next;
                    pre->next->next = currTail;
                    currTail = pre->next;
                    pre->next = tmp;
                }
                pre->next = currTail;
                pre = currHead;
            } else {
                break;
            }
        }
        return new_head->next;
    }
};
