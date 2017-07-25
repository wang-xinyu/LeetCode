/**
 * Burst Balloons
 * 
 * Trick: divide and conquer, i is the last to burst
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(nums);
        num.insert(num.begin(), 1);
        num.push_back(1);
        vector<vector<int>> memory(n+2, vector<int>(n+2, 0));
        return dc(memory, num, 0, n+1);
    }
private:
    int dc(vector<vector<int>> &memory, vector<int>& num, int left, int right) {
        if (left + 1 >= right) return 0;
        if (memory[left][right]) return memory[left][right];
        int ans = 0;
        // divide and conquer, i is the last to burst
        for (int i = left+1; i < right; i++) {
            ans = max(ans, num[left]*num[i]*num[right] + dc(memory, num, left, i) + dc(memory, num, i, right));
        }
        memory[left][right] = ans;
        return ans;
    }
};
