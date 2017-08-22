/**
 * Palindrome Pairs
 *
 * Trick: using hash map, see the following codes
 */
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            map[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string str1 = words[i].substr(0, j);
                string str2 = words[i].substr(j);
                if (isPalindrome(str1)) {
                    string str2rev = str2;
                    reverse(str2rev.begin(), str2rev.end());
                    if (map.count(str2rev) != 0 && map[str2rev] != i) {
                        ans.push_back(vector<int>({map[str2rev], i}));
                    }
                }
                if (!str2.empty() && isPalindrome(str2)) {
                    string str1rev = str1;
                    reverse(str1rev.begin(), str1rev.end());
                    if (map.count(str1rev) != 0 && map[str1rev] != i) {
                        ans.push_back(vector<int>({i, map[str1rev]}));
                    }
                }
            }
        }
        return ans;
    }
private:
    bool isPalindrome(string &str) {
        int i = 0, j = str.size()-1;
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
