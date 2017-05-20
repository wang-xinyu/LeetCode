/**
 * Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxPro = 0, minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};
