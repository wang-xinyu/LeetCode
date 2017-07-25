/**
 * Remove Duplicate Letters
 * 
 * Trick: Greedy?
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return "";
        vector<int> count(26, 0);
        int pos = 0;
        for (int i = 0; i < s.size(); i++) count[s[i] - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < s[pos]) pos = i;
            if (--count[s[i] - 'a'] == 0) break;
        }
        string temp = s.substr(pos+1);
        for (int i = 0; i < temp.size(); i++) {
            while (i < temp.size() && temp[i] == s[pos]) temp.erase(temp.begin()+i);
        }
        return s.substr(pos, 1) + removeDuplicateLetters(temp);
    }
};
