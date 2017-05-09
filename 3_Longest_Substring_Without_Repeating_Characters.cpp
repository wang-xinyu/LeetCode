/**
 * Sliding Window--commonly used in array/string problems.
 * Use the vector, index 0-255 of which represent the 256 Extended ASCII CODE.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, 0);
        int ans=0;
        for(int i=0, j=0; j<s.length(); j++){
            i = max(map[s[j]],i);
            ans = max(ans, j-i+1);
            map[s[j]] = j+1;
        }
        return ans;
    }
};

/**
 * Sliding Window--commonly used in array/string problems.
 * Use unordered_map
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
