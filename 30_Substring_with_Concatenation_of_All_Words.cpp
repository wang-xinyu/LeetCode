/**
 * Substring with Concatenation of All Words
 * Use two hash maps to store the words in 'words' and words seen in 's'
 * Time complexity: O(wl*2*N/wl) = O(2N)
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), m = words.size();
        if (n == 0 || m ==0) return ans;
        unordered_map<string, int> counts;
        for (string w : words) {
            counts[w]++;
        }
        int wl = words[0].size();
        for (int i = 0; i < wl; i++) {
            int left = i, cnt = 0;
            unordered_map<string, int> seen;
            for (int j = left; j < n; j += wl) {
                string str = s.substr(j, wl);
                if (counts.count(str)) {
                    seen[str]++;
                    if (seen[str] <= counts[str]) {
                        cnt++;
                    } else {  // a word shows more than once
                        while (seen[str] > counts[str]) {
                            string str1 = s.substr(left, wl);
                            seen[str1]--;
                            if (seen[str1] < counts[str1]) cnt--;
                            left += wl;
                        }
                    }
                    if (cnt == m) {
                        ans.push_back(left);
                        seen[s.substr(left, wl)]--;
                        cnt--;
                        left += wl;
                    }
                } else {  // word not exits
                    seen.clear();
                    cnt = 0;
                    left = j + wl;  // move to this word's next word
                }
            }
        }
        return ans;
    }
};
