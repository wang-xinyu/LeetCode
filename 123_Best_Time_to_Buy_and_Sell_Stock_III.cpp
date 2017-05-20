/**
 * Best Time to Buy and Sell Stock III
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), minPrice = INT_MAX, maxPrice = INT_MIN, maxPro = 0;
        vector<int> maxProL(n), maxProR(n+1);
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
            maxProL[i] = maxPro;
        }
        maxPro = maxProR[n] = 0;
        for (int i = n-1; i > 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            maxPro = max(maxPro, maxPrice - prices[i]);
            maxProR[i] = maxPro;
        }
        maxPro = 0;
        for (int i = 0; i < n; i++) {
            maxPro = max(maxPro, maxProL[i] + maxProR[i+1]);
        }
        return maxPro;
    }
};
