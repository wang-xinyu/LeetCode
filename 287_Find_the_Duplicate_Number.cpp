/**
 * Find the Duplicate Number 
 *
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // idea from problem 142. Linked List Cycle II
        // treat nums as a linked list, each value of nums is the address of next node
        if (nums.size() < 2) return -1;
        int slow = nums[0], fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
