/**
 *  Climbing Stairs
 *  Fibonacci sequence.
 */
class Solution {
public:
    int climbStairs(int n) {
        int one_step_before = 2, two_steps_before = 1, all_ways = 2;
        for (int i = 2; i < n; i++) {
            all_ways = one_step_before + two_steps_before;
            two_steps_before = one_step_before;
            one_step_before = all_ways;
        }
        return (n == 1) ? two_steps_before : all_ways;
    }
};
