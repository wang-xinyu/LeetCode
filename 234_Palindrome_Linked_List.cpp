/**
 * Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *slow = head, *fast = head;
        int len = 1;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            len++;
        }
        ListNode *p1 = head;
        ListNode *p2 = reverseList(slow->next);
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        dummy1->next = head;
        while (dummy1->next) {
            ListNode *p = dummy2->next;
            dummy2->next = dummy1->next;
            dummy1->next = dummy1->next->next;
            dummy2->next->next = p;
        }
        return dummy2->next;
    }
};
