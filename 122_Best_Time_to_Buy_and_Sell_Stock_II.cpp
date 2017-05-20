/**
 * Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = INT_MAX, maxPro = 0, n = prices.size();
        for (int i = 0; i < n; i++) {
            int curMin = prices[i];
            while (i < n-1 && prices[i+1] >= prices[i]) i++;
            maxPro += prices[i] - curMin;
        }
        return maxPro;
    }
};
