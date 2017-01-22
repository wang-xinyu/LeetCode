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

