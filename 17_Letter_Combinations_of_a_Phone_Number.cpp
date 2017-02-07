/**
 * Letter Combinations of a Phone Number 
 * Time complexity: O(n)
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) return result;
        string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string tmp = map[digits[0] - '0'];
        for (int i = 0; tmp[i] != '\0'; i++) {
            result.push_back(map[(int)digits[0] - '0'].substr(i, 1));
        }
        for (int i = 1; digits[i] != '\0'; i++) {
            if (digits[i] < '2') {
                result.clear();
                return result;
            }
            for (int j = 0; j < result.size();) {
                string str = result[j];
                result.erase(result.begin() + j);
                tmp = map[digits[i] - '0'];
                for (int k = 0; tmp[k] != '\0'; k++, j++) {
                    result.insert(result.begin() + j, str + tmp.substr(k, 1));
                }
            }
        }
        return result;
    }
};
