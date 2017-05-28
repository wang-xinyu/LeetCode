/**
 * Word Break II
 * 
 * DFS with a hashmap to save the previous results.
 */
class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (map.count(s)) return map[s];
        vector<string> ans;
        if (s.empty()) {
            ans.push_back("");
            return ans;
        }
        for (auto word: wordDict) {
            int len = word.size();
            if (s.substr(0, len) == word) {
                vector<string> subans = wordBreak(s.substr(len), wordDict);
                for (int i = 0; i < subans.size(); i++) {
                    ans.push_back((subans[i] != "") ? word + " " + subans[i] : word); 
                }
            }
        }
        map[s] = ans;
        return ans;
    }
};
