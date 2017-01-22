/**
 * Merge k Sorted Lists.
 * Merge two sorted lists fisrt.
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
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *tail = ans;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 != NULL) ? l1 : l2;
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = NULL;
        for (auto l : lists) {
            result = mergeTwoSortedLists(result ,l);
        }
        return result;
    }
};

