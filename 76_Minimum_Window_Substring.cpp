/**
 * Minimum Window Substring
 * Use the "Substr" problem template
 */
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (auto c : t) map[c]++;
        int i = 0, j = 0, n = s.size(), head, d = INT_MAX, count = t.size();
        
        while (j < n) {
            if (map[s[j++]]-- > 0) count--;
            while (count == 0) {
                if (j - i < d) d = j - (head = i);
                if (map[s[i++]]++ == 0) count++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
