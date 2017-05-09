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

/**
 * Merge k Sorted Lists.
 * Use priority queue.
 * Time complexity: O(n*log(k))
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a,ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;

        for (auto headnode : lists) {  // O(k*log(k))
            if(headnode)  queue.push(headnode);
        }

        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        while (!queue.empty()) {  // O(n*log(k))
            tail->next = queue.top();
            queue.pop();
            tail = tail->next;
            if (tail->next) queue.push(tail->next);  // O(log(k))
        }
        return head->next;
    }
};
