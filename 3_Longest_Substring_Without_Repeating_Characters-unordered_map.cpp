/**
 * Sliding Window--commonly used in array/string problems.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int ans=0;
        for(int i=0, j=0; j<s.length(); j++){
            if(map.find(s[j]) != map.end()){
                i = max(map[s[j]]+1,i);
            }
            ans = max(ans, j-i+1);
            map[s[j]] = j;
        }
        return ans;
    }
};

