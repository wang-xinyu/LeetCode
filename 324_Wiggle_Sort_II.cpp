/**
 * Wiggle Sort II
 *
 * Trick: use a priority queue
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int start = 1;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (start < n) {
            nums[start] = pq.top();
            pq.pop();
            start += 2;
        }
        start = 0;
        while (start < n) {
            nums[start] = pq.top();
            pq.pop();
            start += 2;
        }
    }
};
