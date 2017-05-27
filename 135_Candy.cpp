/**
 * Candy
 * The adjacent children with same ratings don't need to be given same number of candies.
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i-1] < ratings[i]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        return accumulate(candies.rbegin(), candies.rend(), 0);
    }
};
