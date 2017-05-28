/**
 * Copy List with Random Pointer
 * 
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> map;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        if (map[head]) return map[head];
        map[head] = new RandomListNode(head->label);
        map[head]->next = copyRandomList(head->next);
        map[head]->random = copyRandomList(head->random);
        return map[head];
    }
};
