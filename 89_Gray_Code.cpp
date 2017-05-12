/**
 * Gray Code
 * 
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int j = 1; j <= n; j++) {
            int len = ans.size(), t = 1 << (j-1);
            for (int i = len-1; i >=0; i--) {
                ans.push_back(ans[i] | t);
            }
        }
        /**
         * Another Solution G(i) = B(i) ^ B(i+1)
         * for (int i = 0; i < 1<<n; i++) result.add(i ^ i>>1);
         */
        return ans;
    }
};
