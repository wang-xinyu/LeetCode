/**
 * Minimum Height Trees
 * 
 * Trick: Remove leaves layer by layer, until only one/two leaves
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if (n == 1) ans.push_back(0);
        if (n <= 1) return ans;
        vector<unordered_set<int>> adj(n);
        for (auto p : edges) {
            adj[p.first].insert(p.second);
            adj[p.second].insert(p.first);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i); 
        }
        
        for (int num = n; num > 2;) {
            num -= leaves.size();
            int len = leaves.size();
            for (int i = 0; i < len; i++) {
                for (auto j : adj[leaves[i]]) {
                    adj[j].erase(leaves[i]);
                    if (adj[j].size() == 1) leaves.push_back(j);
                }
            }
            leaves.erase(leaves.begin(), leaves.begin()+len);
        }
        
        return leaves;
    }
};
