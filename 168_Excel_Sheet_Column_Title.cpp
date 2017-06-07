/**
 * Excel Sheet Column Title
 *
 */
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        for (int i = n-1; i>=0; i = i/26 - 1) {
            int j = i % 26;
            ans.insert(ans.begin(), 'A' + j);
        }
        return ans;
    }
};
