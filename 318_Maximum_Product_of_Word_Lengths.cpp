/**
 * Maximum Product of Word Lengths
 * 
 * Trick: Use a vector to count letters
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, n = words.size();
        for (int i = 0; i < n; i++) {
            vector<int> count(26, 0);
            for (int p = 0; p < words[i].size(); p++) count[words[i][p] - 'a']++;
            for (int j = i+1; j < n; j++) {
                if (noCommonLetters(words, count, j)) ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
private:
    bool noCommonLetters(vector<string>& words, vector<int>& count, int j) {
        for (int p = 0; p < words[j].size(); p++) if (count[words[j][p] - 'a'] > 0) return false;
        return true;
    }
};
